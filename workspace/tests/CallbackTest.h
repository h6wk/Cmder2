/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-10 21:31:22                               *
 * @LastEditDate          : 2023-08-10 21:34:04                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef E1B3814C_BC13_4775_8BBD_0643FFF61F33
#define E1B3814C_BC13_4775_8BBD_0643FFF61F33

#include <gtest/gtest.h>

#include <common/Callback.h>

namespace cmder::tst {

  using cmder::common::Callback;

  class CallbackTest : public testing::Test {
  protected:  // You should make the members protected s.t. they can be accessed from sub-classes.
        
    // Per-test-suite set-up.
    // Called before the first test in this test suite.
    static void SetUpTestSuite()
    {
      sCallback = std::make_shared<Callback>("<<Test>>");
    }

    // Per-test-suite tear-down.
    // Called after the last test in this test suite.
    // Can be omitted if not needed.
    static void TearDownTestSuite()
    {
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

    static Callback::SharedPtr sCallback;
  };
}


#endif /* E1B3814C_BC13_4775_8BBD_0643FFF61F33 */
