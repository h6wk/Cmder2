/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-18 21:37:19                               *
 * @LastEditDate          : 2024-02-18 21:50:46                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <exe/Command.h>

#include <stdexcept>

namespace cmder::exe {
  CommandResult Command::execute(const std::string &command)
  {
    FILE *pipe = popen(command.c_str(), "r");

    if (pipe == nullptr) {
      throw std::runtime_error("popen() failed!");
    }

    try {

    }
    catch (...) {
      pclose(pipe);
      throw;
    }
    
    return CommandResult();
  }
}
