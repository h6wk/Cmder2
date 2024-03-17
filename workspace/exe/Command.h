/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-18 21:36:58                               *
 * @LastEditDate          : 2024-02-18 21:46:24                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef E5E02E99_5788_4D79_A1AE_C0CB347C91AF
#define E5E02E99_5788_4D79_A1AE_C0CB347C91AF

#include <exe/CommandResult.h>
#include <string>

namespace cmder::exe {
  class Command {
  public:
    /**
     * Execute a system command and get bact the STDOUT / STDERR result with exitstatus
     * of the command. 
     */
    static CommandResult execute(const std::string &command);

  };
}

#endif /* E5E02E99_5788_4D79_A1AE_C0CB347C91AF */
