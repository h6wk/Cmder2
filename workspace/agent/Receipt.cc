/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-09 21:01:51                               *
 * @LastEditDate          : 2023-08-09 21:46:32                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <agent/Receipt.h>

#include <common/Types.h>

#include <atomic>
#include <iostream>
#include <ostream>
#include <chrono>


namespace cmder::agent {

  static std::atomic<TaskId_t> sNextTaskId = 0; 

  std::ostream& operator<<(std::ostream& ostr, const ExecutionMode_t& mode)
  {
    switch (mode) {
    case ExecutionMode_t::Async:
      ostr << std::string("async");
      break;
    case ExecutionMode_t::Blocking:
      ostr << std::string("blocking");
      break;
    }
    return ostr;
  }

  Receipt::Receipt(ExecutionMode_t mode)
  : mMode(mode)
  , mTaskId(sNextTaskId++)
  , mStartTime(std::chrono::system_clock::now())
  , mEndTime()
  , mStatus(OK)
  {
  }

  void Receipt::setEndTime()
  {
    mEndTime = std::chrono::system_clock::now();
  }

  ExecutionMode_t Receipt::getExecutionMode() const
  {
    return mMode;
  }

  TaskId_t Receipt::getTaskId() const
  {
    return mTaskId;
  }

  const ChronoTime_t& Receipt::getStartTime() const
  {
    return mStartTime;
  }

  const ChronoTime_t& Receipt::getEndTime() const
  {
    return mEndTime;
  }

  Receipt::Status_t Receipt::getStatus() const
  {
    return mStatus;
  }

  void Receipt::setStatus(Status_t status)
  {
    mStatus = status;
  }

}
