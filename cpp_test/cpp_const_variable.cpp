//
// Created by wuqi on 19-6-30.
//

#include <iostream>
#include <stdio.h>

using namespace std;
static int static_a = 1;
int extern_a = 1;
extern int extern_a;
const int const_a = 1;

int main() {
  const int const_b = 2;
  printf("const_b %d\n", &const_b);
  printf("const_a %d\n", &const_a);
  printf("static_a %d\n", &static_a);
  printf("extern_a %d\n", &extern_a);

  int a;
  int b;
  printf("&a : %d\n", &a);
  printf("&b : %d\n", &b);

//  int *a = (int *) malloc(10);
//  int *b = (int *) malloc(10);
//  printf("a : %d\n", a);
//  printf("b : %d\n", b);

  return 0;
}

//#include<iostream>
//using namespace std;
////用来验证const变量是在什么时期进行初始化的
////c++ 编译器会在编译用常亮对const变量进行替换
//int main(){
//  const int a=10;
//  const int * p=&a;                    //让指针p指向常量a所在的内存
//  int * p_var=const_cast<int *>(p);            //强制转换const指针为非const
//  *p_var=20;                //往该指针所指向的内存写20，也就是把10给覆盖了
//
//  cout<<a<<endl;
//  cout<<(&a)<<endl;
//
//  cout<<*p<<endl;
//  cout<<(p)<<endl;
//
//  cout<<*p_var<<endl;
//  cout<<(p_var)<<endl;
//
//  return 0;
//}

//int a = 0; //全局初始化区
//char *p1; //全局未初始化区
//int main() {
//  int b; //栈
//  char s[] = "abc"; //栈
//  char *p2; //栈
//  char *p3 = "123456"; //123456\0在常量区，p3在栈上。
//  static int c = 0; //全局（静态）初始化区
//  p1 = (char *) malloc(10);
//  p2 = (char *) malloc(20);
//  //分配得来得10和20字节的区域就在堆区。
//  //strcpy(p1, "123456"); //123456\0放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方。
//}