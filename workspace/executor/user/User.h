/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-03-29 21:33:57                               *
 * @LastEditDate          : 2024-03-29 21:55:38                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#pragma once

#include <string>
#include <cstdint>

#include <uuid/uuid.h>

namespace executor::user {

  /// @brief The entity that describes the user
  /// @details The class describes the user that going to execute activities (order). It
  ///          doesn't wait (no blocking) for the result, the agent that was chosen
  ///          for the management of the order will continuously inform the user about
  ///          the status and the results.
  ///          A unique ID identifies the user.
  class User {
  public:

    using UserID = std::string;

    /// @brief The user that will execute activities
    /// @param name 
    explicit User(const std::string& name);
    virtual ~User() = default;

    UserID getUserID() const;

  private:
    const std::string mName;
    const UserID mUserID;    
  };

}
