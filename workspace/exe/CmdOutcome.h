/******************************************************************************
 * @Author                : h6wk<130506947+h6wk@users.noreply.github.com>     *
 * @CreatedDate           : 2024-02-14 22:09:10                               *
 * @LastEditors           : h6wk<130506947+h6wk@users.noreply.github.com>     *
 * @LastEditDate          : 2024-02-14 22:35:16                               *
 * @FilePath              : Cmder2/workspace/exe/CmdOutcome.h                 *
 * @CopyRight             : MerBleueAviation                                  *
 *****************************************************************************/

#ifndef CF5DC6B6_6E77_4756_A106_38988630E8F3
#define CF5DC6B6_6E77_4756_A106_38988630E8F3

#include <string>
#include <ostream>

namespace cmder::exe {
  class CmdOutcome {
  public:
    CmdOutcome();
    virtual ~CmdOutcome() = default;
    

    friend std::ostream& operator<<(std::ostream& os, const CmdOutcome& oc);

  private:
    int32_t mExitCode;
    std::string mStandardOut;
    std::string mStandardError;
  };

  inline std::ostream& operator<<(std::ostream& os, const CmdOutcome& oc)
  {
    os << "exit_code=" << oc.mExitCode;
    return os;
  }

}

#endif /* CF5DC6B6_6E77_4756_A106_38988630E8F3 */

