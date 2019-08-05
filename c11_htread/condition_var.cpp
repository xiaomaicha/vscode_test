//#include <thread>
//#include <iostream>
//#include <mutex>
//#include <list>
//#include <condition_variable>
//
//using namespace std;
//
//std::mutex g_mutex;
//std::condition_variable cond;
//
//std::list<int> alist;
//
//void threadFun1()
//{
//    for (size_t i = 0; i < 10; i++)
//    {
//        /* code */
//        std::unique_lock<std::mutex> ul(g_mutex);
//        std::cout<<"iter:"<<i<<std::endl;
//        while (alist.empty())
//        {
//            cond.wait(ul);
//        }
//
//        std::cout << "threadFun1 get the value : " << alist.front() << std::endl;
//        alist.pop_front();
//    }
//}
//
//void threadFun2()
//{
//    for (size_t i = 0; i < 10; i++)
//    {
//        /* code */
//        std::lock_guard<std::mutex> lg(g_mutex);
//        alist.push_back(i);
//
//        cond.notify_one();
//    }
//}
//
//int main()
//{
//    std::thread th1(threadFun1);
//    std::thread th2(threadFun2);
//
//    th1.join();
//    th2.join();
//
//    cout<<"finish"<<endl;
//
//    return 0;
//}


#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std::chrono;

std::condition_variable_any cv;
std::mutex cv_m;
int i;

void waits(int idx)
{
  std::unique_lock<std::mutex> lk(cv_m);
  if(cv.wait_for(lk, microseconds(idx*100), []{return i == 1;}))
    std::cerr << "Thread " << idx << " finished waiting. i == " << i << '\n';
  else
    std::cerr << "Thread " << idx << " timed out. i == " << i << '\n';
}

void signals()
{
  std::this_thread::sleep_for(microseconds(120));
  std::cerr << "Notifying...\n";
  cv.notify_all();
  std::this_thread::sleep_for(microseconds(10));
  {
    std::lock_guard<std::mutex> lk(cv_m);
    i = 1;
  }
  std::cerr << "Notifying again...\n";
  cv.notify_all();
}

int main()
{
  std::thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
  t1.join(); t2.join(), t3.join(), t4.join();
}