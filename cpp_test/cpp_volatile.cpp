//
// Created by wuqi on 19-7-2.
//

/*
  volatile 指出 i 是随时可能发生变化的，每次使用它的时候必须从 i的地址中读取，
  因而编译器生成的汇编代码会重新从i的地址读取数据放在 b 中。而优化做法是，由于
  编译器发现两次从 i读数据的代码之间的代码没有对 i 进行过操作，它会自动把上次
  读的数据放在 b 中。而不是重新从 i 里面读。这样以来，如果 i是一个寄存器变量
  或者表示一个端口数据就容易出错，所以说 volatile 可以保证对特殊地址的稳定访
  问。注意，在 VC 6 中，一般调试模式没有进行代码优化，所以这个关键字的作用看不
  出来。下面通过插入汇编代码，测试有无 volatile 关键字，对程序最终代码的影响：
 */
#include <stdio.h>
#include <cassert>

#define EQUAL_PTR(a, b) a ==b

//#include <stdio.h>
//int check()
//{
//  int i = 1;
//  i = *(char*)&i;//取 i 的地址 强制类型转换后解引用
//  return i;
//}
//int main(void)
//{
//  if(check()==1)
//    printf("小端模式存储！\n");
//  else
//    printf("大端模式存储！\n");
//  return 0;
//}

int main() {
//  int i = 10;
//  int a = i;
//
//  printf("i = %d", a);
////
////  // 下面汇编语句的作用就是改变内存中 i 的值
////  // 但是又不让编译器知道
////  __asm {
////  mov dword ptr[ebp-4], 20h
////  }
//  int b = i;
//  printf("i = %d", b);

  int c = 0x12345678;
  int p_c = *(char *)&c;
  if(p_c == 0x12){
    printf("大端模式\n");
  } else if(p_c== 0x78){
    printf("小端模式\n");
  }
  printf("低地址：%0xd", p_c);

  const char* char_c1 = "wuqi";
  const char* char_c2 = "wuqi";
  assert(char_c1 == char_c2);

  char array_c1[] = "wuqi";
  char array_c2[] = "wuqi";
  static_assert(array_c1 != array_c2, "");

  return 0;
}