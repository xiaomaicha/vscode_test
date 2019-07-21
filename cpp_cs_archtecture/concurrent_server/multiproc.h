//
// Created by wuqi on 19-7-13.
//

#ifndef VS_TEST_CPP_CS_ARCHTECTURE_CONCURRENT_SERVER_MULTIPROC_H
#define VS_TEST_CPP_CS_ARCHTECTURE_CONCURRENT_SERVER_MULTIPROC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<errno.h>

/*数据传输接收缓冲区长度*/
#define BUF_SZIE 1024
/*监听队列长度*/
#define BACKLOG_SIZE 128
/*客户端地址信息缓冲区长度*/
#define ADDR_PORT_SIZE 40

#endif //VS_TEST_CPP_CS_ARCHTECTURE_CONCURRENT_SERVER_MULTIPROC_H
