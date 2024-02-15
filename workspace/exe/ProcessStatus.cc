/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-15 21:02:41                               *
 * @LastEditDate          : 2024-02-15 22:53:24                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <exe/ProcessStatus.h>
#include <stdexcept>
#include <sys/wait.h>
#include <signal.h>

namespace cmder::exe {

  ProcessStatus::ProcessStatus(int status)
  : mStatus(status)
  {
    if (WIFEXITED(mStatus)) {
      mResult = std::make_tuple<ExitMode, int>(ExitMode::Exited, WEXITSTATUS(mStatus));
    }
    else if (WIFSIGNALED(mStatus)) {
      mResult = std::make_tuple<ExitMode, int>(ExitMode::Signaled, WTERMSIG(mStatus));
    }
    else {
      throw std::runtime_error(std::string("Not accpeted status:") + std::to_string(status));
    }
  }

  ProcessResult ProcessStatus::getStatusResult() const
  {
    return mResult;
  }
}
