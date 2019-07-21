//
// Created by wuqi on 19-7-13.
//

/*client_main.c*/
#include"multiproc.h"
#include "cpp_concurrent_client.h"

int main(int argc, char ** argv)
{
  if(argc < 3){
    printf("Too few parameter!\n");
    exit(EXIT_FAILURE);
  }
  socket_client_create(argv[1], argv[2]);
  return 0;
}