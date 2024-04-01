/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-03-29 21:34:02                               *
 * @LastEditDate          : 2024-04-01 20:52:30                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <executor/user/User.h>

#include <stdlib.h>
#include "User.h"

namespace executor::user {

  User::UserID generateUserID()
  {
    uuid_t binuuid;
    uuid_generate(binuuid);

    char *uuid = static_cast<char*>(malloc(37));
    uuid_unparse_upper(binuuid, uuid);
    
    User::UserID userID(uuid);
    free(uuid);
    return userID;
  }

  User::User(const std::string &name)
  : mName(name)
  , mUserID(generateUserID())
  {
  }

  User::UserID User::getUserID() const
  {
    return mUserID;
  }

  std::string User::getName() const
  {
    return mName;
  }
}
