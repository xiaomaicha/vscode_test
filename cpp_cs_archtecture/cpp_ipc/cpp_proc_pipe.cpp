//
// Created by wuqi on 19-7-13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void ReadPipe(int fd)//读管道
{
  int ret;
  char buf[32] = {0};

  while(1)
  {
    ret = read(fd, buf, sizeof(buf));
    if (-1 == ret)
    {
      perror("read");
      exit(1);
    }
    if (!strcmp(buf, "bye"))
    {
      break;
    }
    printf("read from pipe: %s\n", buf);
    memset(buf, 0, sizeof(buf));
  }
  close(fd);
}

void WritePipe(int fd)//写管道
{
  int ret;
  char buf[32] = {0};

  while (1)
  {
    scanf("%s", buf);
    ret = write(fd, buf, strlen(buf));
    if (-1 == ret)
    {
      perror("write");
      exit(1);
    }
    if (!strcmp(buf, "bye"))
    {
      break;
    }
    memset(buf, 0, sizeof(buf));
  }
  close(fd);
}

int main()
{
  int fd[2];
  int ret;
  pid_t pid;

  ret = pipe(fd);	//创建管道
  if (-1 == ret)
  {
    perror("pipe");
    exit(1);
  }

  pid = fork();  //创建进程
  if (-1 == pid)
  {
    perror("fork");
    exit(1);
  }
  else if (0 == pid)
  {
    close(fd[1]);		//关闭写端口
    ReadPipe(fd[0]);	//fd[0]读数据
  }
  else
  {
    close(fd[0]);		//关闭读端口
    WritePipe(fd[1]);	//fd[1]写数据

    int status;
    wait(&status);
  }
  return 0;
}