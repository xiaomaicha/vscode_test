//
// Created by wuqi on 19-6-30.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>

using namespace std;
static int static_a = 1;
int extern_a = 1;
extern int extern_a;
const int const_a = 1;

void function(const int *a) {
  printf("%s", &a);
}

int *funtion_1() {
//  int* a= new int(1);
  int a[1] = {1};
  return a;
}

int main() {
  const int const_b = 2;
  printf("const_b %x\n", &const_b);
  printf("const_a %x\n", &const_a);
  printf("static_a %x\n", &static_a);
  printf("extern_a %x\n", &extern_a);

  int a;
  int b;
  printf("&a : %x\n", &a);
  printf("&b : %x\n", &b);

  vector<int> vec;
  shared_ptr<int> ptr(new int[10], default_delete<int[]>());
//  int *a = (int *) malloc(10);
//  int *b = (int *) malloc(10);
//  printf("a : %x\n", a);
//  printf("b : %x\n", b);

  {
    int extern_a = 3;
    printf("extern_a %x\n", &extern_a);
  }

//  int *point_a = funtion_1();
//  cout << point_a[0] << endl;

  int array[5] = {0, 1, 2, 3, 4};
  cout<<*(array+2)<<endl;

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