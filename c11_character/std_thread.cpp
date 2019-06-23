#include <iostream>
#include <stdlib.h>
#include <functional>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <memory>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <mutex>

using namespace std;

class ThreadPool {
public:
    typedef std::function<void()> Task;

    ThreadPool(int num)
            : num_(num), maxQueueSize_(0), running_(false) {
    }

    ~ThreadPool() {
        if (running_) {
            stop();
        }
    }

    ThreadPool(const ThreadPool &) = delete;

    void operator=(const ThreadPool &) = delete;

    void setMaxQueueSize(int maxSize) {
        maxQueueSize_ = maxSize;
    }

    void start() {
        assert(threads_.empty());
        running_ = true;
        threads_.reserve(num_);
        for (int i = 0; i < num_; i++) {
            threads_.push_back(std::thread(std::bind(&ThreadPool::threadFunc, this)));
        }
    }

    void stop() {
        {
            std::unique_lock<std::mutex> ul(mutex_);
            running_ = false;
            notEmpty_.notify_all();
        }

        for (auto &iter : threads_) {
            iter.join();
        }
    }

    void run(const Task &t) {
        if (threads_.empty()) {
            t();
        } else {
            std::unique_lock<std::mutex> ul(mutex_);
            while (isFull()) {
                notFull_.wait(ul);
            }
            assert(!isFull());
            queue_.push_back(t);
            notEmpty_.notify_one();
        }
    }

private:
    bool isFull() const {
        return maxQueueSize_ > 0 && queue_.size() >= maxQueueSize_;
    }

    void threadFunc() {
        while (running_) {
            Task task(take());
            if (task) {
                std::lock_guard<std::mutex> lg(mutex_out); //自动锁
                printf("thread id:%d\n", std::this_thread::get_id());
                task();
                printf("thread id:%d\n", std::this_thread::get_id());
            }
        }
    }

    Task take() {
        std::unique_lock<std::mutex> ul(mutex_);
        while (queue_.empty() && running_) {
            notEmpty_.wait(ul);
        }
        Task task;
        if (!queue_.empty()) {
            task = queue_.front();
            queue_.pop_front();
            if (maxQueueSize_ > 0) {
                notFull_.notify_one();
            }
        }
        return task;
    }

private:
    int num_;
    std::mutex mutex_;
    std::mutex mutex_out;
    std::condition_variable notEmpty_;
    std::condition_variable notFull_;
    std::vector<std::thread> threads_;
    std::deque<Task> queue_;
    size_t maxQueueSize_;
    bool running_;
};

void fun() {
    printf("[id:%d] hello, world!\n", std::this_thread::get_id());
}

int main() {
    std::mutex mute;
    std::unique_lock<mutex> lo();
    {
        printf("main thread id:%d\n", std::this_thread::get_id());
        ThreadPool pool(3);
        pool.setMaxQueueSize(100);
        pool.start();
        //std::this_thread::sleep_for(std::chrono::milliseconds(3000));

        for (int i = 0; i < 1000; i++) {
            pool.run(fun);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }

    return 0;
}