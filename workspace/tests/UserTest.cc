/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2024-03-29 22:24:51                               *
 * @LastEditDate          : 2024-04-01 20:56:59                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/


#include <tests/UserTest.h>
#include <executor/user/User.h>


namespace tests {

  using namespace executor::user;

  TEST_F(UserTest, aass)
  {
    User user1("user1");
    std::cout << "UUID: " << user1.getUserID() << std::endl;

    User user2("user2");
    std::cout << "UUID: " << user2.getUserID() << std::endl;

    EXPECT_NE(user1.getUserID(), user2.getUserID());
    EXPECT_EQ(user1.getUserID(), user1.getUserID());
  }
}
