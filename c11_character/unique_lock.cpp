// #include<thread>
// #include<iostream>
// #include<mutex>
// #include<vector>
// #include<iterator>
// #include<time.h>
// #include<random>
// #include<algorithm>
// #include<numeric>

// std::mutex g_mutex;


// void threadFunc(size_t num)
// {
//     //C++ 11保证局部static只会被一个线程初始化
//     static std::default_random_engine random(time(nullptr));
//     static std::uniform_int_distribution<int> dist(0, 100);

//     std::vector<int> vec;
//     vec.reserve(num);

//     std::unique_lock<std::mutex> ul(g_mutex);
//     std::generate_n(std::back_inserter(vec), num, [] {return dist(random); });

//     ul.unlock();//解锁，降低锁的粒度

//     int sum = std::accumulate(vec.begin(), vec.end(), 0);
//     double avg = 1.0*sum / vec.size();

//     ul.lock();
//     std::cout << "thread id " << std::this_thread::get_id() << " obtains avg num = " << avg << std::endl;

//     //ul的析构函数会解锁
// }


// int main()
// {
//     std::thread th1(threadFunc, 100);
//     std::thread th2(threadFunc, 200);

//     th1.join();
//     th2.join();

//     return 0;
// }


#include<thread>
#include<iostream>
#include<mutex>


std::mutex g_mutex;

void threadFun1()
{
    std::unique_lock<std::mutex> ul(g_mutex, std::defer_lock);

    g_mutex.lock();//作死

    std::cout << " in thread Fun1 " << std::endl;
    //由于std::unique_lock并没有记录到g_mutex已经上锁了，所以析构函数并不会调用unlock解锁
}


void threadFun2()
{
    std::lock_guard<std::mutex> lg(g_mutex);
    std::cout << "threadFunc2 get the lock" << std::endl;
}


int main()
{
    std::thread th1(threadFun1);
    std::thread th2(threadFun2);
    th1.join();
    th2.join();

    std::cout << "finish 2 threads" << std::endl;
    return 0;
}

