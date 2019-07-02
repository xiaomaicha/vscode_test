//
// Created by wuqi on 19-6-28.
//

#include <stdarg.h>
#include <stdio.h>
#include <iostream>

//实现变参函数的三种方法
//　　在C++中实现一个变参函数的方法有三种：第一种方法，将函数形参声明为C++11新标准中的initializer_list标准库类型；
// 第二种方法继承自C语言，形参声明为省略符，函数实现时用参数列表宏访问参数；
// 最后一种方法利用C++泛型特性，声明一个可变参数模板来实现。
//
//　　1. 可变参数宏
//　　实现步骤如下：
//　　　　１. 函数原型中使用省略号；
//　　　　２. 函数定义中创建一个va_list变量；
//　　　　3. 初始化va_list变量；
//　　　　4. 访问参数列表；
//　　　　5. 完成清理工作；
//　　上述步骤的实现需要使用到四个宏：va_list、va_start(va_list, arg)、va_arg(va_list, type)、va_end(va_list)这些宏在头文件stdarg.h中声明定义。因此使用时需要包含该头文件。
//

int sum_1(int count, ...);  //原型中使用省略号

#define sum(count, ...) sum_1(count, __VA_ARGS__)


int sum_1(int count, ...){
  va_list ap;               //声明一个va_list变量
  va_start(ap, count);      //初始化，第二个参数为最后一个确定的形参

  int sum = 0;
  for (int i = 0; i < count; i++)
    sum += va_arg(ap, int); //读取可变参数，的二个参数为可变参数的类型

  va_end(ap);               //清理工作
  return sum;
}

//这三个点用在宏中就是变参宏（Variadic Macros），默认名称为__VA_ARGS__。
//应该是在函数（宏）声明与定义的时候使用...，在调用变参的时候采用__VA_ARGS__的形式；
//#define WriteLine(...) { printf(__VA_ARGS__); putchar('\n');}
#define WriteLine (...) printf(__VA_ARGS__) + (putchar('\n') != EOF ? 1: 0)

int main() {
  int result = sum(5, 1, 2, 3, 4, 5);
  std::cout << "result: " << result << std::endl;

//  int i = WriteLine("MoreWindows");
//
//  WriteLine("%d", i);
//
  int j = printf("%s\n", "MoreWindows");

//
//  WriteLine("%d", j);  return 0;
}