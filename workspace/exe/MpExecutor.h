/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-11 21:16:11                               *
 * @LastEditDate          : 2024-02-11 22:28:10                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef FBDBCD46_4823_4132_8C5A_00FA743A0731
#define FBDBCD46_4823_4132_8C5A_00FA743A0731

#include <string>

namespace cmder::exe {

  class MpExecutor {
  public:
    MpExecutor();
    virtual ~MpExecutor();

    /// @brief Blocking call to execute a system command/script
    static void run(const std::string& command);
  };
}

#endif /* FBDBCD46_4823_4132_8C5A_00FA743A0731 */
