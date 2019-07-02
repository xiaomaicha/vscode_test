//
// Created by wuqi on 19-6-8.
//
#include <stdio.h>
#include <iostream>
#include <typeinfo>

//区分c还是c++符号
#ifdef __cplusplus
extern "C" {
#endif

/* functions */
char *strdup (const char *s);

#ifdef __cplusplus
}
#endif

//宏替换
//#转化陈字符串
//##字符串的链接
#define ADD(a, b) (a) + b
#define STR(s)     #s
#define CONS(a, b)  int(a##e##b)

//分级进行宏展开
#define  _GET_FILE_NAME(f)   #f
#define  GET_FILE_NAME(f)    _GET_FILE_NAME(f)

//宏进行字符大小的获取
#define  _TYPE_BUF_SIZE(type)  sizeof(#type)
#define  TYPE_BUF_SIZE(type)   _TYPE_BUF_SIZE(type)

//宏进行结构体的填充
#define  FILL(a)   {a, #a}
enum class IDD{OPEN, CLOSE};
struct MSG{
  IDD id;
  const char * msg;
};

//宏进行变量的声明与定义
#define  ___ANONYMOUS1(type, var, line)  type  var##line
#define  __ANONYMOUS0(type, line)  ___ANONYMOUS1(type, _anonymous, line)
#define  ANONYMOUS(type)  __ANONYMOUS0(type, __LINE__)

using namespace std;
int main() {
  int a = 1, b = 2;
  cout << "macro replace:ADD " << ADD(a, b) << endl;

  static char FILE_NAME[] = GET_FILE_NAME(__FILE__);

  char buf[TYPE_BUF_SIZE(0x7fffffff)];

  MSG _msg[] = {FILL(IDD::OPEN), FILL(IDD::CLOSE)};

  ANONYMOUS(static int) = 1;

  printf(STR(vck));           // 输出字符串"vck"
  printf("\n");
  printf("%d\n", CONS(2, 3));  // 2e3 输出:2000

//输出日期、时间、源文件名、所在行
//Data-Time:Sep 29 2018	  11:55:19	FileName:test.cpp Line:31
  printf("Data-Time:%s  %s  FileName:%s  Line:%d\n", __DATE__, __TIME__,
         __FILE__, __LINE__);


//cpp文件会被编译成c++的格式__cplusplus
//c文件只有使用gcc编译时才不会定义__cplusplus,如果使用g++编译则会定义
#ifdef __cplusplus
  printf("__cplusplus exist\n");
  printf("__cplusplus: %ld\n", __cplusplus);
#else
  printf("__cplusplus not exist\n");
#endif

//通过“-D __DEBUG”开关灵活控制启用不同的代码

//#define __Debug_mode

//if(__Debug_mode == 1){
//  printf("__Debug_mode: %d\n", __Debug_mode);
////  cout<<__Debug_mode<<endl;
//  cout<<"macro type: "<< typeid(__Debug_mode).name()<<endl;
//}

#ifdef __Debug_mode
  printf("__Debug_mode: %d\n", __Debug_mode);
  cout<<"macro type: "<< typeid(__Debug_mode).name()<<endl;
  printf("in Debug\n");
#else
  printf("in Release\n");
#endif

  return 0;
}