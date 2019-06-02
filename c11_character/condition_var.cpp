#include<thread>
#include<iostream>
#include<mutex>
#include<list>
#include<condition_variable>

std::mutex g_mutex;
std::condition_variable cond;

std::list<int> alist;

void threadFun1()
{
    std::unique_lock<std::mutex> ul(g_mutex);
    while (alist.empty())
    {
        cond.wait(ul);
    }

    std::cout << "threadFun1 get the value : " << alist.front() << std::endl;
    alist.pop_front();
}

void threadFun2()
{
    std::lock_guard<std::mutex> lg(g_mutex);
    alist.push_back(13);

    cond.notify_one();
}

int main()
{
    std::thread th1(threadFun1);
    std::thread th2(threadFun2);

    th1.join();
    th2.join();

    return 0;
}