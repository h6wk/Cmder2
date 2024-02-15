/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 21:18:42                               *
 * @LastEditDate          : 2024-02-15 22:36:13                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <exe/OsExecutor.h>
#include <exe/ProcessStatus.h>

#include <common/Logger.h>

#include <iostream>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

namespace cmder::exe {

  void childProcess(const std::string& command, int pipefd[2])
  {
    (void)close(pipefd[0]); // Close unused read end

    FILE *fp = popen(command.c_str(), "r");
    if (nullptr == fp) {
      int popenErrno = errno;
      std::stringstream errSS;
      errSS << "popen(" << command << ") errno "   << popenErrno;
      LOG(errSS.str());
      return;
    }

    const size_t MAX_COMMAND_RESULT = 1000;
    char commandResult[MAX_COMMAND_RESULT];
    while (fgets(commandResult, MAX_COMMAND_RESULT, fp) != NULL) { // read line by line
      printf("*** %s", commandResult);
    }

    const int statusInt = pclose(fp);
    const ProcessStatus status(statusInt);
    LOG(status);


    const std::string messageToParent("Hello Parent!");
    (void)write(pipefd[1], messageToParent.c_str(), messageToParent.size());

    (void)close(pipefd[1]); // Close write end - last message was sent
  }

  CmdOutcome OsExecutor::run(const std::string& command, IpcMode mode)
  {
    LOG(command);

    int pipefd[2];
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

      childProcess(command, pipefd);
      
      exit(0);
    }

    CmdOutcome retVal;
    
    LOG("The outcome is: " << retVal);
    return retVal;
  }
}
