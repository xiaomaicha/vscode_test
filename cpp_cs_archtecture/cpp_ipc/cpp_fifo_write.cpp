//
// Created by wuqi on 19-7-13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  int fd;
  int ret;
  char buf[32] = {0};

  fd = open("fifo.tmp", O_WRONLY);//以只写方式打开文件fifo.tmp
  while (1)
  {
    scanf("%s", buf);

    ret = write(fd, buf, strlen(buf));//写入数据到文件
    if (-1 == ret)
    {
      perror("write");
      exit(1);
    }

    if (!strcmp(buf, "bye"))//输入bye结束写入
    {
      break;
    }
    memset(buf, 0, sizeof(buf));
  }

  close(fd);
  return 0;
}