/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-13 20:33:31                               *
 * @LastEditDate          : 2023-08-13 21:25:48                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <agent/Agent.h>

#include <assert.h>
#include <future>
#include <random>
#include <string>

namespace {

  /// @brief Helper method to generate an ID for the next agent instance
  /// @return String in form of "Name_1234"
  std::string getNextAgentName()
  {
    static const std::array<std::string, 6> sAgentNames{
      "Mulder", "Scully", "Bond", "Bourne", "Hunt", "Nikita"
    };
    
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distrName(0, sAgentNames.max_size());
    static std::uniform_int_distribution<int> distrId(100, 999);
    std::stringstream ss;
    ss << "<<" << sAgentNames[distrName(generator)] << "_" << distrId(generator) << ">>";
    return ss.str();
  }
}

namespace cmder::agent {

  using cmder::srv::Server;

  std::ostream& operator<<(std::ostream& ostr, const Status& status)
  {
    switch (status) {
    case Status::Init:
      ostr << "INIT";
      break;
    case Status::Run:
      ostr << "RUN";
      break;
    case Status::Start:
      ostr << "START";
      break;
    case Status::Stop:
      ostr << "STOP";
      break;
    }
    return ostr;
  }


  Agent::SharedPtr Agent::create(Server& server, Callback::SharedPtr callbackUser)
  {
    //Use a temporary subclass to make a connection between a smart pointer generator function and a class with a private constructor.
    struct MkSharedEnabler : public Agent {
      MkSharedEnabler(Server& server, Callback::SharedPtr cb) : Agent(server, cb) {}
    };
    auto instance = std::make_shared<MkSharedEnabler>(server, callbackUser);

    return instance;
  }


  Receipt Agent::doTask(ExecutionMode_t mode, const TaskName& task, std::string& result) const
  {
    Receipt receipt(mode);

    result.clear();

    LOG("Task '" << task << "' started in " << mode << " mode");
    if (auto cbUserSP = mCallbackUser.lock()) {
      cbUserSP->notify(receipt.getTaskId(), CallbackMessageType_t::NOTIFICATION, "Task started: " /*+ task*/);
    }
    else {
      assert(mode != ExecutionMode_t::Async);
    }

    // This is the Agent's internal thread!
    std::future<std::string> futureResult = std::async([&mode, this, &receipt]() {

      //pthread_setname_np(pthread_self(), "TH_EXECUTOR");

      using namespace std::chrono_literals;

      LOG("Executor thread start");
      std::this_thread::sleep_for(1000ms);
      LOG("Executor thread stop");

      const std::string result("3.14");

      if (mode == ExecutionMode_t::Async) {
        auto cbUserSP = mCallbackUser.lock();
        if (cbUserSP) {
          cbUserSP->notify(receipt.getTaskId(), CallbackMessageType_t::RESULT, result);
        }
        return std::string("");
      }

      return result;
      });


    switch (mode) {
    case ExecutionMode_t::Async:
      // TODO: register the future in a store, put the result later into the callback
      break;
    case ExecutionMode_t::Blocking:
      // The client's thred is blocked until the future is not calculated!
      result = futureResult.get();
      break;
    }

    LOG("Leaving method with return value: " << result);

    receipt.setEndTime();
    return receipt;
  }


  const std::string& Agent::getName() const
  {
    return mDebugName;
  }

  void Agent::registerAgent()
  {
    // TODO: check the call Agent::create()
  }

  void Agent::unregisterAgent()
  {
    mServer.unregisterAgent(mDebugName);
  }

  uint64_t Agent::statNotification(const std::string& notificationName) const
  {
    std::lock_guard guard(mMutex);
    if (mCallbackAgent) {
      return mCallbackAgent->size();
    }
    return 0;
  }

  Agent::Agent(Server &server, Callback::SharedPtr callbackUser)
  : mMutex()
  , mThreadPtr()
  , mConditionVariable()
  , mServer(server)
  , mCallbackUser(callbackUser)
  , mDebugName(getNextAgentName())
  , mCallbackAgent(std::make_shared<Callback>(mDebugName))
  {
    {
      std::lock_guard guard(mMutex);
      mStatus = Status::Init;
    }

    server.registerAgent(mDebugName, mCallbackAgent);

    LOG("Agent " << mDebugName << " created. Status set to " << mStatus);
  }

  void Agent::run()
  {
    using namespace std::chrono_literals;

    {
      std::lock_guard guard(mMutex);
      mStatus = Status::Run;
    }

    LOG("Agent " << mDebugName << " runs");

    while (true) {

      std::unique_lock ul(mMutex);
      if (mStatus == Status::Stop) {break;}

      mConditionVariable.wait_for(ul, 500ms);
    }

    LOG("Agent-thread quits");
  }

  Agent::~Agent()
  {
    stop();

    if (mThreadPtr) {
      mThreadPtr->join();
    }
    LOG("Deleted");
  }

  void Agent::start()
  {
    // restart is not supported! need to destroy the object and join the thread 
    assert(mStatus == Status::Init);

    mThreadPtr = std::make_unique<std::thread>(&Agent::run, this);
    std::lock_guard guard(mMutex);
    mStatus = Status::Start;
  }

  void Agent::stop()
  {
    {
      std::lock_guard guard(mMutex);
      mStatus = Status::Stop;
    }

    // Don't need to hold the lock while calling notify_all()
    mConditionVariable.notify_all();
  }

  Status Agent::getStatus() const
  {
    std::lock_guard guard(mMutex);
    return mStatus;
  }

}
