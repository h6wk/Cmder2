/*****************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                          *
 * @CreatedDate           : 2023-08-08 11:17:28                              *
 * @LastEditDate          : 2023-08-08 21:54:17                              *
 * @CopyRight             : GNU GPL                                          *
 ****************************************************************************/

#ifndef D87A54F2_0FA8_41D7_9D3A_A75725911E44
#define D87A54F2_0FA8_41D7_9D3A_A75725911E44

#include <cstdint>
#include <string>

namespace cmder {

  class IStatProvider {
  public:
    virtual uint64_t statNotification(const std::string& notificationName) const = 0;
  };

}

#endif /* FED2C17D_5272_4374_9F47_1EACE7280CF1 */
