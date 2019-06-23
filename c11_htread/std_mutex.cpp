//
// Created by wuqi on 19-6-8.
//

#include <iostream>
#include <stdlib.h>
#include <thread>
#include <string>
#include <mutex>

int g_num = 0;
std::mutex g_mutex;

void thread1()
{
    g_mutex.lock();     //线程加锁
    g_num = 10;
    for (int i=0; i<10; i++)
    {
        std::cout << "thread1:" << g_num <<"\tthread id:\t"<< std::this_thread::get_id() << std::endl;
    }
    g_mutex.unlock();
}

void thread2()
{
    std::lock_guard<std::mutex> lg(g_mutex); //自动锁
    g_num = 20;
    for (int i=0; i<10; i++)
    {
        std::cout << "thread2:" << g_num <<"\tthread id:\t"<< std::this_thread::get_id() << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    if(t1.joinable()) t1.join();
//    t1.join();
//    std::thread t3 = t2; //thread 对象禁止复制。 thread& operator= (const thread&) = delete;
    std::thread t3 = std::move(t2);
    if(t3.joinable()) t3.join();
    return 0;
}