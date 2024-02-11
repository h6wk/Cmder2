/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 21:18:42                               *
 * @LastEditDate          : 2024-02-11 22:29:34                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <exe/MpExecutor.h>
#include <iostream>

namespace cmder::exe {

  MpExecutor::MpExecutor()
  {
  }

  MpExecutor::~MpExecutor()
  {
  }

  void MpExecutor::run(const std::string& command)
  {
    std::cout << "\nCMD:" << command;
  }
}
