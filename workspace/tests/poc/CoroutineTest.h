/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-17 21:47:57                               *
 * @LastEditDate          : 2023-08-18 21:34:43                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef B3418E95_CB2E_4244_9A19_574022B4BBA4
#define B3418E95_CB2E_4244_9A19_574022B4BBA4

#include <gtest/gtest.h>


namespace cmder::tst::poc {

  class CoroutineTest : public testing::Test {
  protected:  // You should make the members protected s.t. they can be accessed from sub-classes.
        
    // Per-test-suite set-up.
    // Called before the first test in this test suite.
    static void SetUpTestSuite()
    {
    }

    // Per-test-suite tear-down.
    // Called after the last test in this test suite.
    // Can be omitted if not needed.
    static void TearDownTestSuite()
    {
    }

    // virtual void SetUp() will be called before each test is run.
    void SetUp() override
    {
    }

    // virtual void TearDown() will be called after each test is run. You should define it if there is cleanup work to do.
    //virtual void TearDown() {
    //}
  };

}


#endif /* B3418E95_CB2E_4244_9A19_574022B4BBA4 */
