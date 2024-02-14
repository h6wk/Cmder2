/******************************************************************************
 * @Author                : h6wk<130506947+h6wk@users.noreply.github.com>     *
 * @CreatedDate           : 2024-02-11 21:16:11                               *
 * @LastEditors           : h6wk<130506947+h6wk@users.noreply.github.com>     *
 * @LastEditDate          : 2024-02-14 22:13:32                               *
 * @FilePath              : Cmder2/workspace/exe/MpExecutor.h                 *
 * @CopyRight             : MerBleueAviation                                  *
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
  

  class MpExecutor {
  public:
    MpExecutor();
    virtual ~MpExecutor();

    /// @brief Blocking call to execute a system command/script
    static CmdOutcome run(const std::string& command, IpcMode mode = IpcMode::Pipe);
  };
}

#endif /* FBDBCD46_4823_4132_8C5A_00FA743A0731 */
