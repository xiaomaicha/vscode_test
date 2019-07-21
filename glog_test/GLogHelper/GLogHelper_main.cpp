//
// Created by wuqi on 19-7-6.
//

#include "GLogHelper.h"

int main(int argc,char* argv[])
{
  //要使用 GLOG ，只需要在 main 函数开始处添加这句即可
  GLogHelper gh(argv[0]);

  LOG(INFO)<<"INFO";
  LOG(ERROR)<<"ERROR";
}