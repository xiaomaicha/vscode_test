//
// Created by wuqi on 19-7-13.
//

#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <malloc.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <fcntl.h>

int main()
{
  int sockClient = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in addrSrv{};
  addrSrv.sin_addr.s_addr = inet_addr("127.0.0.1");
  addrSrv.sin_family = AF_INET;
  addrSrv.sin_port = htons(8765);
  connect(sockClient, ( const struct sockaddr *)&addrSrv, sizeof(struct sockaddr_in));

  char szBuf[2048] = {0};
  int iRet = recv(sockClient, szBuf, sizeof(szBuf) - 1 , 0);
  printf("msg from server: %s\n", szBuf);

  getchar();
  close(sockClient);

  return 0;
}