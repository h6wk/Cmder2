/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-13 20:00:13                               *
 * @LastEditDate          : 2023-08-13 21:07:58                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef FA924E50_EE65_40C4_AD44_B968C9D86491
#define FA924E50_EE65_40C4_AD44_B968C9D86491

#include <agent/Receipt.h>
#include <agent/Task.h>

#include <server/Server.h>

#include <common/IControllableThread.h>
#include <common/IStatProvider.h>

#include <memory>

namespace cmder::agent {

  using cmder::IControllableThread;
  using cmder::IStatProvider;

  using namespace cmder::srv;

  /**
   * Client uses the agent to get access to a service. This represents a layer
   * between the client and the service layer. In a multi service environment the
   * agent can select the proper service provider.
   * 
   * Accepts the task and forwards to the selected service. Accepts the service's
   * response and distributes to the client's callback.
   */
  class Agent : public IControllableThread, public IStatProvider
  {
  public:
    using SharedPtr = std::shared_ptr<Agent>;

    /// @brief Create a new Agent object.
    /// @param server Reference to the server that will be called to do the task
    /// @param callback Shared pointer to the callback (async!)
    ///                 Empty pointer -> only blocking mode is possible
    /// @return Shared pointer on the newly created object.
    static SharedPtr create(Server& server, Callback::SharedPtr callback);

    virtual ~Agent();

    //////////////////////////////////////////////////////////////////////////
    // IControllableThread abstract interface implementations:              //
    void start() override;                                                  //
    void stop() override;                                                   //
    Status getStatus() const override;                                      //
    //////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////////////
    // IStatProvider abstract interface implementations:                            //
    uint64_t statNotification(const std::string& notificationName) const override;  //
    //////////////////////////////////////////////////////////////////////////////////


    /// @brief Invoke a task and get the result of it
    /// @param mode Blocking the caller or asynch (NOTE: only blocking works now)
    /// @param task Name of task
    /// @param result The result in blocking mode. In async mode the result is pushed
    ///         into the callbak.
    /// @return Get back a receipt of ackowledge that can be used to find the corresponding
    ///         async result.
    Receipt doTask(ExecutionMode_t mode, const TaskName& task, std::string& result) const;

    /// @brief Get the name of the agent (for debugging).
    ///        It is automatically generated at the time of creation.
    /// @return Name as a string constant reference.
    const std::string& getName() const;

    // Helpers to set up/break down the link between the agent and the server (for testing purposes)
    void registerAgent();
    void unregisterAgent();

  private:
    explicit Agent(Server& server, Callback::SharedPtr callback);

    /// @brief The method that will be executed by the working thread.
    void run();

    mutable std::mutex mMutex;                //< Protect data containers against data race

    std::unique_ptr<std::thread> mThreadPtr;  //< Thread responsible to accept notifications from
                                              //< the server and forward them to the client.
                                              //< NOTE: another worker thread is created to execute the task (doTask()).

    std::condition_variable mConditionVariable; //< For the control of the thread

    Status mStatus;                           //< The status of mThreadPtr

    Server& mServer;                          //< As of now the only service. Later the
                                              //< service will be selected for a task based on
                                              //< some selection criteria.

    Callback::WeakPtr mCallbackUser;          //< User's callback to send async responses
                                              //< Since this ia a weak pointer, agent doesn't own it!

    std::string mDebugName;                   //< To name (ID) for better logging

    Callback::SharedPtr mCallbackAgent;       //< Agent's callback to receive notifications and async responses from the server
  };

  std::ostream& operator<<(std::ostream& ostr, const Status& status);


}

#endif /* FA924E50_EE65_40C4_AD44_B968C9D86491 */
