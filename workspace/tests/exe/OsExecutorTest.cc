/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 22:11:02                               *
 * @LastEditDate          : 2024-02-15 10:53:14                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <tests/exe/OsExecutorTest.h>

namespace cmder::tst::exe {

  TEST_F(OsExecutorTest, FirstTest)
  {
    [[maybe_unused]] auto outcome = OsExecutor::run("ls -al");
  }
}
