/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-08 09:34:14                               *
 * @LastEditDate          : 2023-08-08 09:38:26                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <agent/Task.h>

namespace cmder::agent {

  std::ostream& operator<<(std::ostream& ostr, const TaskName& task)
  {
    switch (task) {
    case TaskName::BlockMe_3s:
      ostr << "BLOCK_ME_3s";
      break;
    case TaskName::Pi:
      ostr << "PI";
      break;
    case TaskName::PingMe_5x:
      ostr << "PING_ME_5x";
      break;
    }
    return ostr;
  }


}

