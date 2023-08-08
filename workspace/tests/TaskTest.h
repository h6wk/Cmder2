/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-08 20:29:15                               *
 * @LastEditDate          : 2023-08-08 20:39:22                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef DCB9787E_069F_405D_ADF8_C4A52F71F9B6
#define DCB9787E_069F_405D_ADF8_C4A52F71F9B6

#include <agent/Task.h>

//  mingw-w64-x86_64-gtest !
#include <gtest/gtest.h>


namespace cmder::tst {

  using namespace cmder::agent;

  // To use gtest fixture, derive from testing::Test 
  class TaskTest : public testing::Test {
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

#endif /* DCB9787E_069F_405D_ADF8_C4A52F71F9B6 */
