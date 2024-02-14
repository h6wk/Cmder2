/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 22:11:02                               *
 * @LastEditDate          : 2024-02-11 22:30:53                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <tests/exe/MpExecutorTest.h>

namespace cmder::tst::exe {

  TEST_F(MpExecutorTest, FirstTest)
  {
    MpExecutor::run("ls -al");
  }
}
