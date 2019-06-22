#pragma once

#include<list>
#include<mutex>
#include<thread>
#include<condition_variable>
#include <iostream>

template<typename T>
class SyncQueue {
private:
    bool IsFull() const {
        return m_queue.size() == m_maxSize;
    }

    bool IsEmpty() const {
        return m_queue.empty();
    }

public:
    SyncQueue(int maxSize) : m_maxSize(maxSize) {
    }

    void Put(const T &x) {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notFull.wait(locker, [this] {
            if (!IsFull()) {
                return true;
            } else {
                std::cout << "缓冲区满了，需要等待..." << std::endl;
                m_notFull.notify_one();
                return false;
            }
        });

//		while (IsFull())
//		{
//			std::cout << "缓冲区满了，需要等待..." << std::endl;
//			m_notFull.wait(m_mutex);
//		}

        m_queue.push_back(x);
        std::cout << "put" << std::endl;

        m_notFull.notify_one();
    }

    void Take(T &x) {
        std::unique_lock<std::mutex> locker(m_mutex);

        m_notEmpty.wait(locker, [this] {
            if(!IsEmpty()){
                return true;
            } else{
                std::cout << "缓冲区空了，需要等待..." << std::endl;
                m_notFull.notify_one();
                return false;
            }
        });
//
//		while (IsEmpty())
//		{
//			std::cout << "缓冲区空了，需要等待..." << std::endl;
//			m_notEmpty.wait(m_mutex);
//		}

        x = m_queue.front();
        m_queue.pop_front();
        std::cout << "take" << std::endl;
        m_notFull.notify_one();
    }

    bool Empty() {
        std::unique_lock<std::mutex> locker(m_mutex);
        return m_queue.empty();
    }

    bool Full() {
        std::unique_lock<std::mutex> locker(m_mutex);
        return m_queue.size() == m_maxSize;
    }

    size_t Size() {
        std::unique_lock<std::mutex> locker(m_mutex);
        return m_queue.size();
    }

    int Count() {
        return m_queue.size();
    }

private:
    std::list<T> m_queue;                  //缓冲区
    std::mutex m_mutex;                    //互斥量和条件变量结合起来使用
    std::condition_variable_any m_notEmpty;//不为空的条件变量
    std::condition_variable_any m_notFull; //没有满的条件变量
    int m_maxSize;                         //同步队列最大的size
};