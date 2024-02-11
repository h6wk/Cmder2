/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 21:58:48                               *
 * @LastEditDate          : 2024-02-11 22:13:58                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef D140F00C_3F4E_42FE_9966_20D6605E0D25
#define D140F00C_3F4E_42FE_9966_20D6605E0D25

#include <exe/MpExecutor.h>

//  mingw-w64-x86_64-gtest !
#include <gtest/gtest.h>


namespace cmder::tst::exe {

  using namespace cmder;
  using namespace cmder::exe;

  // To use gtest fixture, derive from testing::Test 
  class MpExecutorTest : public testing::Test {
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
    }

    // virtual void TearDown() will be called after each test is run. You should define it if there is cleanup work to do.
    virtual void TearDown() {
    }
  };
}

#endif /* D140F00C_3F4E_42FE_9966_20D6605E0D25 */
