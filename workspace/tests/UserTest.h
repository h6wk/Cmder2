/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-03-29 22:23:49                               *
 * @LastEditDate          : 2024-03-29 22:25:56                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef A9824D10_9C17_49F5_9EE7_D955FFF91B3F
#define A9824D10_9C17_49F5_9EE7_D955FFF91B3F

#include <gtest/gtest.h>

namespace tests {

  class UserTest : public testing::Test {
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

#endif /* A9824D10_9C17_49F5_9EE7_D955FFF91B3F */
