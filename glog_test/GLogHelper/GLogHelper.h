//
// Created by wuqi on 19-7-6.
//

#ifndef VS_TEST_GLOG_TEST_GLOGHELPER_GLOGHELPER_H
#define VS_TEST_GLOG_TEST_GLOGHELPER_GLOGHELPER_H
#include <glog/logging.h>
#include <glog/raw_logging.h>

//将信息输出到单独的文件和 LOG(ERROR)
void SignalHandle(const char *data, int size);

class GLogHelper {
public:
  //GLOG配置：
  GLogHelper(char *program);
  //GLOG内存清理：
  ~GLogHelper();
};

#endif //VS_TEST_GLOG_TEST_GLOGHELPER_GLOGHELPER_H
