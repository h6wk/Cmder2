/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-07 21:06:53                               *
 * @LastEditDate          : 2023-08-07 21:47:58                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef A3A03BBB_9DE6_4CF6_94E2_EBC455361B89
#define A3A03BBB_9DE6_4CF6_94E2_EBC455361B89

#include <tools/ThreadPool.h>

//  mingw-w64-x86_64-gtest !
#include <gtest/gtest.h>


namespace cmder::tst {

  using namespace cmder::tools;

  // To use gtest fixture, derive from testing::Test 
  class ThreadPoolTest : public testing::Test {
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
      if (mThreadPool) {
        mThreadPool.release();
      }
    }

    std::unique_ptr<ThreadPool> mThreadPool;
  };

}


#endif /* A3A03BBB_9DE6_4CF6_94E2_EBC455361B89 */
