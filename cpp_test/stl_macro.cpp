//
// Created by wuqi on 19-6-8.
//
#include <stdio.h>


int main(){
//输出日期、时间、源文件名、所在行
//Data-Time:Sep 29 2018	  11:55:19	FileName:test.cpp Line:31
    printf("Data-Time:%s  %s  FileName:%s  Line:%d\n", __DATE__, __TIME__,
           __FILE__, __LINE__);


//cpp文件会被编译成c++的格式__cplusplus
//c文件只有使用gcc编译时才不会定义__cplusplus,如果使用g++编译则会定义
#ifdef __cplusplus
    printf("__cplusplus exist\n");
#else
    printf("__cplusplus not exist\n");
#endif

//通过“-D __DEBUG”开关灵活控制启用不同的代码

//#define __Debug_mode

#ifdef __Debug_mode
    printf("in Debug\n");
#else
    printf("in Release\n");
#endif

//#ifndef _ZX_FUNC_H
//#define _ZX_FUNC_H
//
//#ifdef __cplusplus
//    extern "C" {
//#endif
//
///* functions */
//    char *strdup (const char *s);
//
//#ifdef __cplusplus
//    }
//#endif
//
//#endif

}