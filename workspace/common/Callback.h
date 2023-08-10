/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-08-10 09:56:24                               *
 * @LastEditDate          : 2023-08-10 10:09:25                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef B0C71682_DC38_4C96_9EB6_B923C79E3631
#define B0C71682_DC38_4C96_9EB6_B923C79E3631

#include <common/Types.h>

#include <chrono>
#include <condition_variable>
#include <queue>
#include <memory>
#include <string>

namespace cmder::common {

  /**
   * Object shared between the entities communicating with eachother asynchronously.
   * 
   * The owner of the object is supposed to be the "receiver", that expects to receive
   * the message from the "sender" some time later. The "receiver" keeps a shared pointer
   * on the callback, the "sender" a weak pointer.
   * 
   * If the "receiver" cannot lock the weak pointer anymore, the "receiver" lifetime has
   * been ended.
   */
  class Callback
  {
  public:
    using SharedPtr = std::shared_ptr<Callback>;
    using WeakPtr = std::weak_ptr<Callback>;

    struct Message_t {
      ChronoTime_t mTime;
      TaskId_t mTaskId;
      CallbackMessageType_t mType;
      std::string mText;
    };

    explicit Callback(const std::string& owner);
    virtual ~Callback();

    /// @brief Add a new message into the callback's queue
    void notify(TaskId_t taskId, CallbackMessageType_t type, const std::string& message);

    /// @brief Clean the messages from the callback's queue
    void clear();

    /// @brief Get back a message (if exists)
    ///        Note, this is a non-blocking call!
    /// @return An std::optional that might include the Message (or not).
    std::optional<Message_t> tryPop();

    /// @brief Wait until a type of message arrives into the callback. This is a BLOCKING call!
    ///        Note, if the message exists, will be moved from the callback into the std::optional
    /// @return An std::optional that might include the Message (or not).
    std::optional<Message_t> pop();

    /// @brief Get back the number of messages stored actually within the callback.
    /// @return Unsigned integer
    size_t size() const;

    /// @brief Check the emptyness of the internal queue
    /// @return Boolean
    bool empty() const;

    friend std::ostream& operator<<(std::ostream& ostr, const Callback::SharedPtr& cb);

  private:

    mutable std::mutex mMutex;                  //< Protect data containers against data race
    std::condition_variable mConditionVariable; //< For the sync between threads
    std::string mOwnerName;
    std::queue<Message_t> mMessages;            //< Message queue
  };

  std::ostream& operator<<(std::ostream& ostr, const Callback::SharedPtr& cb);
}

#endif /* B0C71682_DC38_4C96_9EB6_B923C79E3631 */
