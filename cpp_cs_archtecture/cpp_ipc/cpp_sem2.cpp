//
// Created by wuqi on 19-7-14.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>

#define SHMKEY 1234
#define SHMSIZE 4096
#define SEMKEY 1234

union semun {
  int val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short *array;  /* Array for GETALL, SETALL */
  struct seminfo *__buf;  /* Buffer for IPC_INFO(Linux specific) */
};

void sem_p(int semid) {
  int ret;
  struct sembuf sbuf;

  sbuf.sem_num = 0;//第一个
  sbuf.sem_op = -1;//P操作
  sbuf.sem_flg = SEM_UNDO;//SEM_UNDO进程异常自动UNDO

  ret = semop(semid, &sbuf, 1);
  if (ret == -1) {
    perror("semop_p");
    return;
  }
}
void sem_v(int semid) {
  int ret;
  struct sembuf sbuf;

  sbuf.sem_num = 0;//第一个
  sbuf.sem_op = 1;//V操作
  sbuf.sem_flg = SEM_UNDO;//SEM_UNDO进程异常自动UNDO

  ret = semop(semid, &sbuf, 1);
  if (ret == -1) {
    perror("semop_v");
    return;
  }
}

int main() {
  int shmid;
  void *shmaddr;
  int count = 0;
  int semid;
  union semun unsem;

  semid = semget(SEMKEY, 1, 0);    //获取信号量
  if (-1 == semid) {
    perror("semget");
    exit(1);
  }

  //unsem.val = 1;
  //semctl(semid, 0, SETVAL, unsem);//初始化信号量

  shmid = shmget(SHMKEY, SHMSIZE, 0);//获取共享内存
  if (-1 == shmid) {
    perror("shmget");
    exit(1);
  }

  shmaddr = shmat(shmid, NULL, 0);//映射到虚拟地址空间
  if (NULL == shmaddr) {
    perror("shmat");
    exit(1);
  }

  while (1) {
    sem_p(semid);//P操作

    count = *(int *) shmaddr;//从内存读数据
    usleep(100000);

    if (count > 100) {
      break;
    }

    printf("B:%d\n", count);
    count++;

    *(int *) shmaddr = count;//数据写回内存

    //usleep(100000);

    sem_v(semid);//V操作
  }

  shmdt(shmaddr);        //解除映射
  return 0;
}