//
// Created by wuqi on 19-7-13.
//

/*server_main.c*/
#include<multiproc.h>
#include"cPP_concurrent_server.h"

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Too few parameter!\n");
    exit(EXIT_FAILURE);
  }

  socket_server_create(argv[1], argv[2]);
  return 0;
}