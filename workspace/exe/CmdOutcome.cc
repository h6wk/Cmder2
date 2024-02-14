/******************************************************************************
 * @Author                : h6wk<130506947+h6wk@users.noreply.github.com>     *
 * @CreatedDate           : 2024-02-14 22:09:10                               *
 * @LastEditors           : h6wk<130506947+h6wk@users.noreply.github.com>     *
 * @LastEditDate          : 2024-02-14 22:10:21                               *
 * @FilePath              : Cmder2/workspace/exe/CmdOutcome.cc                *
 * @CopyRight             : MerBleueAviation                                  *
 *****************************************************************************/

#include <exe/CmdOutcome.h>

namespace cmder::exe {
  CmdOutcome::CmdOutcome()
  : mExitCode(0)
  , mStandardOut()
  , mStandardError()
  {
    
  }

}