//
// Created by wuqi on 19-7-13.
//

#ifndef VS_TEST_CPP_CS_ARCHTECTURE_CONCURRENT_SERVER_CPP_CONCURRENT_SERVER_H
#define VS_TEST_CPP_CS_ARCHTECTURE_CONCURRENT_SERVER_CPP_CONCURRENT_SERVER_H

#include<multiproc.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/wait.h>

void sys_err(const char *);
void socket_server_create(const char *, const char *);
void fork_create(const int, const int, const struct sockaddr_in *);
void deal_connect(const int, const struct sockaddr_in *);
void write_logfile(const struct sockaddr_in *);

#endif //VS_TEST_CPP_CS_ARCHTECTURE_CONCURRENT_SERVER_CPP_CONCURRENT_SERVER_H
