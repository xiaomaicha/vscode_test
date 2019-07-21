////
//// Created by wuqi on 19-7-13.
////
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//#include <signal.h>
//#include <unistd.h>
//#include <sys/wait.h>
//
//#define LOOP_NUM 5 //create process number
//
//int main()
//{
//
//  int idx=0;
//  pid_t childpid=0;
//  char cmd[16]={0,};
//
//  printf("LOOP start:--> \n");
//  while (1)
//  {
//    if(idx>=LOOP_NUM)
//    {
//      break;
//    }
//    idx++;
//
//    printf(" create pid=%d ppid=%d idx=%d \n", getpid(), getppid(), idx);
//    childpid = fork();
//
//    if (childpid == 0)
//    {
//      // 子进程中
//      printf("  C runing 1 pid=%d ppid=%d idx=%d \n", getpid(), getppid(), idx);
//      sleep(1);
//      printf("  C runing 2 pid=%d ppid=%d idx=%d \n", getpid(), getppid(), idx);
//      //
//      break;
//    }
//    else if (childpid > 0)
//    {
//      // 父进程中
//    }
//    else
//    {
//      //错误
//      printf("fork error pid=%d idx=%d \n", getpid(), idx);
//      wait(nullptr);
//    }
//  }
//
//  //父进程中回收资源
//  if(childpid > 0)
//  {
//    //childpid is child process pid in the parent process
//    printf("FIRST PROCESS:parent create process finished! waiting for children pid=%d childpid=%d \n", getpid(), childpid);
//    sprintf(cmd,"ps -ef | grep %d",getpid());
//    system(cmd);
//    //printf("\n\n %s \n\n", cmd);
//    wait(nullptr);
//    printf("FIRST PROCESS: all exit & wait over pid=%d \n", getpid());
//  }
//  else
//  {
//    printf("  <--pid=%d  ppid=%d childpid=%d idx=%d will exit \n", getpid(), getppid(), childpid, idx);
//  }
//  //exit(0);
//
//  return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv) {
  int flag = 0;
  pid_t pId = fork();
  if (pId == -1) {
    perror("fork error");
    exit(EXIT_FAILURE);
  } else if (pId == 0) {
    int myPid = getpid();
    int parentPid = getppid();
    printf("Child:SelfID=%d ParentID=%d \n", myPid, parentPid);
    flag = 123;
    printf("Child:flag=%d %p \n", flag, &flag);
    int count = 0;
    do {
      count++;
      sleep(1);
      printf("Child count=%d \n", count);
      if (count >= 5) {
        break;
      }
    } while (1);
    return EXIT_SUCCESS;
  } else {
    printf("Parent:SelfID=%d MyChildPID=%d \n", getpid(), pId);
    flag = 456;
    printf("Parent:flag=%d %p \n", flag, &flag); // 连地址都一样,说明是真的完全拷贝,但值已经是不同的了..
    int count = 0;
    do {
      count++;
      sleep(1);
      printf("Parent count=%d \n", count);
      if (count >= 2) {
        break;
      }
    } while (1);
  }
  return EXIT_SUCCESS;
}
