/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-09-01 19:12:00                               *
 * @LastEditDate          : 2023-09-01 19:13:25                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef F43A5695_AD46_4955_B767_39F58AAF87B2
#define F43A5695_AD46_4955_B767_39F58AAF87B2


#include <gtest/gtest.h>

#include <com/Node.h>

namespace cmder::tst {


  class NodeTest : public testing::Test {
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


#endif /* F43A5695_AD46_4955_B767_39F58AAF87B2 */
