/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 21:18:42                               *
 * @LastEditDate          : 2024-02-11 22:29:34                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <exe/MpExecutor.h>

#include <common/Logger.h>

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

  CmdOutcome MpExecutor::run(const std::string& command, IpcMode mode)
  {
    LOG(command);

    int    pipefd[2];
    if (pipe(pipefd) == -1) {
      perror("Cannot create pipe for inter process communication");
      exit(EXIT_FAILURE);
    }

    const pid_t pid = fork();
    if (pid == -1) {
      throw std::runtime_error("Cannot fork child process - errno: " + errno);
    }
    else if (pid > 0) {
      LOG("This is the PARENT " << getpid() << ". My CHILD is " << pid);

      (void)close(pipefd[1]);          /* Close unused write end */

      char buf;
      std::string message;
      while (read(pipefd[0], &buf, 1) > 0) {
        //write(STDOUT_FILENO, &buf, 1);
        message += buf;
      }
      //write(STDOUT_FILENO, "\n", 1);
      std::cout << "\nMessage read from pipe: '" << message << "'" << std::endl;

      (void)close(pipefd[0]);

      waitpid(pid, 0, 0);
    }
    else {
      LOG("This is the child " << getpid());

      (void)close(pipefd[0]);          /* Close unused read end */

      const std::string messageToParent("Hello Parent!");
      (void)write(pipefd[1], messageToParent.c_str(), messageToParent.size());
      (void)close(pipefd[1]);          /* Close write end */

      exit(0);
    }

    CmdOutcome retVal;
    
    LOG("The outcome is: " << retVal);
    return retVal;
  }
}
