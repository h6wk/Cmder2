/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-14 20:41:31                               *
 * @LastEditDate          : 2023-08-14 20:48:14                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef D1C1E98B_59A1_47AC_B7A9_6CAEF4E6C0A3
#define D1C1E98B_59A1_47AC_B7A9_6CAEF4E6C0A3

#include <server/Server.h>
#include <agent/Agent.h>

//  mingw-w64-x86_64-gtest !
#include <gtest/gtest.h>


namespace cmder::tst {

  using namespace cmder;
  using namespace cmder::agent;
  using cmder::srv::Server;

  // To use gtest fixture, derive from testing::Test 
  class ServerTest : public testing::Test {
  protected:  // You should make the members protected s.t. they can be accessed from sub-classes.
    
    // Per-test-suite set-up.
    // Called before the first test in this test suite.
    static void SetUpTestSuite() {
    }

    // Per-test-suite tear-down.
    // Called after the last test in this test suite.
    // Can be omitted if not needed.
    static void TearDownTestSuite() {
    }

    // virtual void SetUp() will be called before each test is run.
    void SetUp() override {
      mServer = std::make_unique<Server>();
    }

    // virtual void TearDown() will be called after each test is run. You should define it if there is cleanup work to do.
    virtual void TearDown() {
      if (mServer) {
        mServer.release();
      }
    }


    std::unique_ptr<Server> mServer;
  };
}

#endif /* D1C1E98B_59A1_47AC_B7A9_6CAEF4E6C0A3 */
