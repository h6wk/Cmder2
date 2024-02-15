/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 21:16:11                               *
 * @LastEditDate          : 2024-02-15 10:51:07                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef FBDBCD46_4823_4132_8C5A_00FA743A0731
#define FBDBCD46_4823_4132_8C5A_00FA743A0731

#include <exe/CmdOutcome.h>

#include <string>

namespace cmder::exe {

  enum class IpcMode {
    Pipe = 1
    , PipeAsync = 2
    , File = 4
    , SharedMemory = 8
  };
  

  class OsExecutor {
  public:
    OsExecutor() = default;
    virtual ~OsExecutor() = default;

    /// @brief Blocking call to execute a system command/script
    static CmdOutcome run(const std::string& command, IpcMode mode = IpcMode::Pipe);
  };
}

#endif /* FBDBCD46_4823_4132_8C5A_00FA743A0731 */
