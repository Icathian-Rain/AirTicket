#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool
{
public:
    ThreadPool(size_t);
    template <class F, class... Args>          //类模板
    auto enqueue(F &&f, Args &&...args)
        -> std::future<typename std::result_of<F(Args...)>::type>;          //任务入队
    ~ThreadPool();

private:

    std::vector<std::thread> workers;           //线程队列

    std::queue<std::function<void()>> tasks;    //任务队列，每个元素为一个函数对象

    // synchronization
    std::mutex queue_mutex;                     //互斥量
    std::condition_variable condition;          //条件变量
    bool stop;
};


inline ThreadPool::ThreadPool(size_t threads)   //向线程队列worker插入threads个线程
    : stop(false)
{
    for (size_t i = 0; i < threads; ++i)
        workers.emplace_back(                   //每个线程对象用lambda函数初始化
            [this]
            {
                for (;;)                        //每个lambda都一直循环着从任务队列中取出任务来执行
                {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);   //给互斥量加锁，锁对象生命周期结束后自动解锁
                        this->condition.wait(lock,
                                             [this]
                                             { return this->stop || !this->tasks.empty(); });
                        //调用条件变量的wait()函数等待条件发生
                        //任务队列为空时会阻塞线程，并且对互斥量解锁
                        //任务队列不为空并且收到条件变量通知后，wait函数使线程解阻塞，并对互斥量加锁
                        if (this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());  //从任务队列里弹出一个任务，对互斥量自动解锁并执行
                        this->tasks.pop();
                    }

                    task();
                }
            });
}

// 添加任务
template <class F, class... Args>
auto ThreadPool::enqueue(F &&f, Args &&...args)
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;      //获取函数返回值类型
    //typename告诉C++编译器，后面的字符串为一个类型名称

    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        if (stop)               //避免任务添加到停止的线程池
            throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task]()     //添加到任务队列，对互斥量自动解锁
                      { (*task)(); });
    }
    condition.notify_one();         //使得阻塞到这个条件变量的线程解阻塞，即唤醒某个等待wait的线程
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers)
        worker.join();
}

#endif