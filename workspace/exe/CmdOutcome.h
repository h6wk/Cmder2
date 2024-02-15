/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-14 22:09:10                               *
 * @LastEditDate          : 2024-02-15 10:43:59                               *
 * @CopyRight             : GNU GPL                                           *
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
