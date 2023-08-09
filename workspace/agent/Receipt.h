/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-09 21:01:51                               *
 * @LastEditDate          : 2023-08-09 21:40:52                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef F39AA2B7_290B_47E7_A935_50D0339ECDA3
#define F39AA2B7_290B_47E7_A935_50D0339ECDA3

#include <common/Types.h>

#include <iostream>

namespace cmder::agent {

  using namespace cmder::common;

  /**
   * Ackowledgement or recipt (of the task)
   */
  class Receipt
  {
  public:
    enum Status_t {OK, FAIL};

    /// @brief Construct a receipt up to the mode.
    /// @param mode 
    explicit Receipt(ExecutionMode_t mode);

    /// @brief Set the end time just before the return to the client
    void setEndTime();

    /// @brief Get the execution mode
    /// @return mode value 
    ExecutionMode_t getExecutionMode() const;

    /// @brief Get the task id. Unique id representing the task.
    /// @return Integer value representing the task
    TaskId_t getTaskId() const;

    const ChronoTime_t& getStartTime() const;
    const ChronoTime_t& getEndTime() const;

    Status_t getStatus() const;
    void setStatus(Status_t status);
  private:
    const ExecutionMode_t mMode;
    const TaskId_t mTaskId;
    ChronoTime_t mStartTime;
    ChronoTime_t mEndTime;
    Status_t mStatus;
  };

  std::ostream& operator<<(std::ostream& ostr, const ExecutionMode_t& mode);
}

#endif /* F39AA2B7_290B_47E7_A935_50D0339ECDA3 */
