/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-14 22:09:10                               *
 * @LastEditDate          : 2024-02-15 10:44:22                               *
 * @CopyRight             : GNU GPL                                           *
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
