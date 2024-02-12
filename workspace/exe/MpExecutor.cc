/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 21:18:42                               *
 * @LastEditDate          : 2024-02-11 22:29:34                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <exe/MpExecutor.h>
#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

    const pid_t pid = fork();
    if (pid > 0) {
      std::cout << "\nThis is the PARENT " << getpid() << ". My CHILD is " << pid;
      waitpid(pid, 0, 0);
    }
    else {
      std::cout << "\nThis is the child " << getpid();
      exit(0);
    }

  }
}
