//
// Created by wuqi on 19-7-13.
//

#include "cpp_concurrent_client.h"
#include<multiproc.h>


void sys_err(const char * ptr_err)
{
  perror(ptr_err);
  exit(EXIT_FAILURE);
}
void socket_client_create(const char * ipaddr, const char * port)
{
  struct sockaddr_in serveraddr;

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = inet_addr(ipaddr);
  serveraddr.sin_port = htons(atoi(port));

  int ret = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
  if(ret < 0)
    sys_err("connect");

  deal_connect(sockfd);
  close(sockfd);
}

void deal_connect(const int sockfd)
{
  char buf[BUF_SZIE] = {};
  while(1){
    bzero(&buf, strlen(buf));//每次清空
    int ret = read(sockfd , buf, sizeof(buf));//循环读取服务器回射信息
    if(ret < 0)
      sys_err("read");
    write(STDOUT_FILENO, buf, strlen(buf));//将接收到的回射信息写到标准输出上
    if(strcmp(buf, "quit success!\n") == 0)//接收到的信息为“quit success!\n”时，表明服务器将客户端请求（sleep(10)模拟）信息处理完毕
      break;
  }
}