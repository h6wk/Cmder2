/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-02-15 21:02:11                               *
 * @LastEditDate          : 2024-02-15 22:49:03                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef CEB6950C_7A6B_4FBD_BBDE_429924D3D9DE
#define CEB6950C_7A6B_4FBD_BBDE_429924D3D9DE

#include <ostream>
#include <tuple>

namespace cmder::exe {

  enum class ExitMode
  {
    Exited, Signaled
  };

  using ProcessResult = std::tuple<ExitMode, int>;

  class ProcessStatus {
  
  public:
    explicit ProcessStatus(int status);
    virtual ~ProcessStatus() = default;

    ProcessResult getStatusResult() const;

    friend std::ostream& operator<<(std::ostream& os, const ProcessStatus& ps);
  
  private:
    const int mStatus;
    ProcessResult mResult;
  };

  inline std::ostream& operator<<(std::ostream& os, const ProcessStatus& ps)
  {
    const auto& [exitMode, exitCode] = ps.mResult;
    os << "exit_mode:" << (int)exitMode << " exit_code:" << exitCode;
    return os;
  }

}

#endif /* CEB6950C_7A6B_4FBD_BBDE_429924D3D9DE */
