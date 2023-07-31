/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-07-31 20:43:59                               *
 * @LastEditDate          : 2023-07-31 20:54:56                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#ifndef A07D525A_3B9B_4F33_9131_C067AA4A5496
#define A07D525A_3B9B_4F33_9131_C067AA4A5496

#include <condition_variable>
#include <functional>
#include <future>
#include <queue>
#include <thread>
#include <vector>

#include "Logger.h"

#include <concepts>

namespace cmder::tools {

  class ThreadPool {
  public:

    // Removed move and copy constructors/operators:
    ThreadPool(const ThreadPool &) = delete;
    ThreadPool(ThreadPool &&) = delete;
    ThreadPool &operator=(const ThreadPool &) = delete;
    ThreadPool &operator=(ThreadPool &&) = delete;

    /// @brief Construct a new pool with a predefined number of threads in it
    /// @param threadCount 
    explicit ThreadPool(size_t threadCount);
    
    virtual ~ThreadPool();

    /// @brief Accept, store and later execute a new task.
    /// @tparam F Callable object type to be executed
    /// @tparam ...Args Argument types to pass the callable object
    /// @param f The callable task
    /// @param ...args Arguments of the task
    /// @return Future that will contain the result
    template<class F, class... Args>
    requires std::invocable<F, Args...>
    std::future<std::result_of_t<F(Args...)>> execute(F &&f, Args &&...args);

  private:

    std::vector<std::thread> mThreads;        //< Container that holds the threads
    std::queue<std::function<void()>> mTasks; //< Queue that stores the tasks that are accepted but not started yet

    std::mutex mMutex;                        //< Protects the tasks queue and the stop flag
    std::condition_variable mConditionVariable;
    bool mStopThreadPool = false;             //< Indicate to stop the operation and destroy the object
  };

  template <class F, class... Args>
  requires std::invocable<F, Args...>
  inline std::future<std::result_of_t<F(Args...)>> ThreadPool::execute(F &&f, Args &&...args)
  {
    LOG("Task accepted");

    using return_type = std::result_of_t<F(Args...)>;
    auto task = std::make_shared<std::packaged_task<return_type()>>(
      std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> res = task->get_future();

    { // mutex scope start
      std::unique_lock lock(mMutex);

      if (mStopThreadPool) {
        throw std::runtime_error("Thread pool has been stopped already");
      }

      // Shared pointer wrapper (no return value)
      mTasks.emplace([task]() -> void { (*task)(); });
    } // mutex scope end

    // notify a thread!
    mConditionVariable.notify_one();

    return res;
  }

}

#endif /* A07D525A_3B9B_4F33_9131_C067AA4A5496 */
