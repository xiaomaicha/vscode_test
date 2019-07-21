//
// Created by wuqi on 19-7-13.
//

#include<stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int t;

void print(int a)
{
  system("clear");//清屏
  alarm(1);//1秒后给当前进程发送一个SIGALRM信号，一直在执行
  printf("%d\n", (t++)%60);

}

int main()
{
  system("clear");//清屏
  alarm(1);//1秒后给当前进程发送一个SIGALRM信号，只执行一次
  signal(SIGALRM, print);

  while (1);//必须有，不然进程就直接结束了

  return 0;
}