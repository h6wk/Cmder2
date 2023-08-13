/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-13 20:29:15                               *
 * @LastEditDate          : 2023-08-13 20:51:00                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef A119B341_1BCA_4E80_ABAA_6378B9496862
#define A119B341_1BCA_4E80_ABAA_6378B9496862

#include <common/AgentInfo.h>
#include <common/IControllableThread.h>
#include <common/IStatProvider.h>

#include <common/Logger.h>

#include <map>

namespace cmder::srv {

  using namespace cmder::common;
  using cmder::IControllableThread;
  using cmder::IStatProvider;
  
  /**
   * Entity that accepts the task does the job and delivers the result to the
   * agent. It can work in sync or async mode, that depends on the type of 
   * the task.
   */
  class Server : public IControllableThread, public IStatProvider {
  public:
    
    Server();
    virtual ~Server();

    //////////////////////////////////////////////////////////////////////////////////
    // IControllableThread abstract interface implementations:                      //
    //////////////////////////////////////////////////////////////////////////////////
    void start() override;                                                          //
    void stop() override;                                                           //
    Status getStatus() const override;                                              //
    //////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////////////
    // IStatProvider abstract interface implementations:                            //
    //////////////////////////////////////////////////////////////////////////////////
    uint64_t statNotification(const std::string& notificationName) const override;  //
    //////////////////////////////////////////////////////////////////////////////////


    /// @brief Registers an agent into the server (for notifications)
    void registerAgent(const std::string& agentName, const Callback::SharedPtr& callback);

    /// @brief Temp. solution to remove an agent. Not completely safe to identify the agent with a generated name.
    /// @param agentName to remove
    void unregisterAgent(const std::string& agentName);

  private:
    void unregisterAgentUnsafe(const std::string& agentName);

    void run();

    mutable std::mutex mMutex;                  //< Protect data containers against data race

    std::unique_ptr<std::thread> mThreadPtr;    //< Do internal calculations. Send notifications

    std::condition_variable mConditionVariable; //< For the control of the thread

    Status mStatus;                             //< The status of mThreadPtr
    
    using AgentCont_t = std::map<AgentName_t, AgentInfo>;
    AgentCont_t mAgents;                        //< List of agents that registered itself. The agent lifetime is not
                                                //< known. Need to lock to test the existence of it

    std::map<std::string, uint64_t> mNotificationStatistics;  //< Nr. of notifications sent of a given type
  };

}

#endif /* A119B341_1BCA_4E80_ABAA_6378B9496862 */
