#include <thread>
#include <iostream>
#include <mutex>
#include <list>
#include <condition_variable>

using namespace std;

std::mutex g_mutex;
std::condition_variable cond;

std::list<int> alist;

void threadFun1()
{
    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        std::unique_lock<std::mutex> ul(g_mutex);
        std::cout<<"iter:"<<i<<std::endl;
        while (alist.empty())
        {
            cond.wait(ul);
        }

        std::cout << "threadFun1 get the value : " << alist.front() << std::endl;
        alist.pop_front();
    }
}

void threadFun2()
{
    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        std::lock_guard<std::mutex> lg(g_mutex);
        alist.push_back(i);

        cond.notify_one();
    }
}

int main()
{
    std::thread th1(threadFun1);
    std::thread th2(threadFun2);

    th1.join();
    th2.join();

    cout<<"finish"<<endl;

    return 0;
}