#include <iostream>
#include <functional>

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
    return n1;
}

struct Foo {
    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }
    static void static_func(std::function<int(int)> f,int n)
    {
        std::cout<<"call static_func\n";
        std::cout<<"f(n):\t"<<f(n)<<"\n";
    }
    int data = 10; //c++11 支持声明是就初始化值
};

int main()
{
    using namespace std::placeholders;

    // std::cref(n) 表示要把n以引用的方式传入
    int n = 7;
    auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
    n = 10;
    f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused

    // 绑定一个子表达式，用_3替换了 其他位置的变量
    // std::bind(g, _3) 在这里已经表示int
    auto f2 = std::bind(f, _4, std::bind(g, _4), _4, 4, 5);
    f2(10, 11, 12 ,13);

    // 绑定成员函数
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, foo, 95, _1);
    f3(5);

    // 绑定成员变量
    auto f4 = std::bind(&Foo::data, _1);
    std::cout << f4(foo) << '\n';


    // 绑定静态成员函数
    auto f5 = std::bind(&Foo::static_func,g,_1);

    f5(3);
}//
// Created by wuqi on 19-6-8.
//

