/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-08 09:34:02                               *
 * @LastEditDate          : 2023-08-08 09:45:37                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef C9174211_6697_44F7_BE2F_A6FA2B517FBF
#define C9174211_6697_44F7_BE2F_A6FA2B517FBF

#include <iosfwd>
#include <iostream>
#include <vector>

namespace cmder::agent {

  /// @brief Hardcoded task names to build regression tests for
  enum class TaskName {Pi, BlockMe_3s, PingMe_5x};

  /// @brief Entity describes a task request that was set by the user at
  ///        the Agent. The Agent manages the task (send to the server, collect data, send
  ///        response and notification back to the user.)
  class Task {
  public:
    struct TaskConfig {

    };


  private:
    std::vector<TaskConfig> mTaskConfiguration;

  };

  std::ostream& operator<<(std::ostream& ostr, const TaskName& task);
}

#endif /* C9174211_6697_44F7_BE2F_A6FA2B517FBF */
