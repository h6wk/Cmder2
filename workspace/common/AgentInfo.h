/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-13 20:48:16                               *
 * @LastEditDate          : 2023-08-13 20:49:55                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef E78A8D83_5209_486E_BCDE_EF88135B7A3B
#define E78A8D83_5209_486E_BCDE_EF88135B7A3B

#include <common/Callback.h>
#include <common/Logger.h>

#include <string>

namespace cmder::common {

  using AgentName_t = std::string;


  struct AgentInfo {
    explicit AgentInfo(const AgentName_t& n, const Callback::SharedPtr& sp)
    : mAgentName(n)
    , mHasCallback(sp ? true : false)
    , mCallback(sp)
    {
      LOG("Registration info for " << mAgentName << " hasCallbak=" << mHasCallback);
    }
    
    AgentName_t mAgentName;
    bool mHasCallback;
    Callback::WeakPtr mCallback;
  };
}


#endif /* E78A8D83_5209_486E_BCDE_EF88135B7A3B */
