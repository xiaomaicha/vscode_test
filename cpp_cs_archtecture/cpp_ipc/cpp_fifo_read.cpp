
//
// Created by wuqi on 19-7-13.
//

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  char buf[32] = {0};
  int fd;
  int ret;

  fd = mkfifo("fifo.tmp", S_IRWXU);//创建有名管道
  if (-1 == fd)
  {
    perror("mkfifo");
    exit(1);
  }

  fd = open("fifo.tmp", O_RDONLY);//只读方式打开文件fifo.tmp
  if (-1 == fd)
  {
    perror("open");
    exit(1);
  }

  while(1)
  {
    ret = read(fd, buf, sizeof(buf));//从文件中读取数据
    if (-1 == ret)
    {
      perror("read");
      exit(1);
    }

    if (!strcmp(buf, "bye"))//读取到bye结束循环
    {
      break;
    }

    printf("read:%s\n", buf);
    memset(buf, 0, sizeof(buf));
  }

  close(fd);
  unlink("fifo.tmp");//在管道使用结束后删除文件fifo.tmp
  return 0;
}