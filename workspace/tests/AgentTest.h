/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-13 21:56:18                               *
 * @LastEditDate          : 2023-08-13 21:57:57                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef BCC76404_DD7D_473D_B6C2_018B66183CB4
#define BCC76404_DD7D_473D_B6C2_018B66183CB4

#include <gtest/gtest.h>

#include <agent/Agent.h>

namespace cmder::tst {

  using cmder::srv::Server;
  using namespace cmder::agent;

  class AgentTest : public testing::Test {
  protected:  // You should make the members protected s.t. they can be accessed from sub-classes.
        
    // Per-test-suite set-up.
    // Called before the first test in this test suite.
    static void SetUpTestSuite()
    {
      sCallback = std::make_shared<Callback>("<<User>>");
      sNoCallbackAgent = Agent::create(sServer, Callback::SharedPtr());
      sAsyncAgent = Agent::create(sServer, sCallback);
    }

    // Per-test-suite tear-down.
    // Called after the last test in this test suite.
    // Can be omitted if not needed.
    static void TearDownTestSuite()
    {
      sAsyncAgent.reset();
      sNoCallbackAgent.reset();
      sCallback.reset();
    }

    // virtual void SetUp() will be called before each test is run.
    void SetUp() override
    {
      sCallback->clear();
    }

    // virtual void TearDown() will be called after each test is run. You should define it if there is cleanup work to do.
    //virtual void TearDown() {
    //}

    static Server sServer;
    static Callback::SharedPtr sCallback;
    static Agent::SharedPtr sNoCallbackAgent;
    static Agent::SharedPtr sAsyncAgent;
  };
}



#endif /* BCC76404_DD7D_473D_B6C2_018B66183CB4 */
