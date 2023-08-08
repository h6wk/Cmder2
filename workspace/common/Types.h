/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-08 21:33:10                               *
 * @LastEditDate          : 2023-08-08 21:33:35                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef C6EC2622_D219_4531_95F0_294A0B76CF09
#define C6EC2622_D219_4531_95F0_294A0B76CF09

#include <chrono>
#include <cstdint>

#define NO_TASK_ID 0u
#define INVALID_TASK_ID 0xFFFFFFFF

namespace cmder {

  using ChronoTime_t = std::chrono::time_point<std::chrono::system_clock>;

  using TaskId_t = uint32_t;

  enum class ExecutionMode_t {
    Async, Blocking
  };

  enum class CallbackMessageType_t {
    NOTIFICATION, RESULT
  };

#endif /* C6EC2622_D219_4531_95F0_294A0B76CF09 */
