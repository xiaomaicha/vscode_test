//
// Created by wuqi on 19-6-9.
//

#include <iostream>

void func()
{
    //...
}

struct Foo
{
    void operator()()
    {
        //...
    }
};

struct Bar
{
    using fr_t = void(*)();

    static void func()
    {
        //...
    }

    operator fr_t()
    {
        return func;
    }
};

struct A
{
    int a_;

    void mem_func()
    {
        //...
    }
};

int main()
{
    void(*func_ptr)() = func;  //函数指针
    func_ptr();

    Foo foo;  //仿函数
    foo();

    Bar bar;  //可被转换为函数指针的类对象
    bar();

    void(A::*mem_func_ptr)() = &A::mem_func;  //类成员函数指针
    int A::*mem_obj_ptr = &A::a_;  //类成员指针

    A aa;
    (aa.*mem_func_ptr)();
    aa.*mem_obj_ptr = 123;

    int* a = new int(1);
    delete a;
    a = nullptr;
    delete a;

    getchar();
    return 0;
}