//
// Created by wuqi on 19-7-6.
//

#include <iostream>
#include <glog/logging.h>
#include <gflags/gflags.h>

int main(int argc, char *argv[]) {
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);
  google::SetLogDestination(google::GLOG_FATAL, "./log/log_fatal_"); // 设置 google::FATAL 级别的日志存储路径和文件名前缀
  google::SetLogDestination(google::GLOG_ERROR, "./log/log_error_"); //设置 google::ERROR 级别的日志存储路径和文件名前缀
  google::SetLogDestination(google::GLOG_WARNING, "./log/log_warning_"); //设置 google::WARNING 级别的日志存储路径和文件名前缀
  google::SetLogDestination(google::GLOG_INFO, "./log/log_info_"); //设置 google::INFO 级别的日志存储路径和文件名前缀

  // 通过GFLAGS来设置参数，更多选项可以在logging.cc里面查询
  // 日志等级分为INFO, WARNING, ERROR, FATAL,如果是FATAL级别这直接运行报错
//  FLAGS_stderrthreshold = google::WARNING;
  FLAGS_colorlogtostderr = true;
//  std::cout << "log level:" << int(FLAGS_stderrthreshold) << std::endl;

  LOG(WARNING) << "Hello GLOG";
  // 条件输出
  LOG_IF(INFO, 20 > 10) << "20 > 10";
  // 频率输出，本质上是通过google::COUNTER这个计数机实现的
  for (int i = 0; i < 10; i++) {
    LOG_EVERY_N(ERROR, 3) << "每隔3次输出一次 " << i;
    LOG_FIRST_N(ERROR, 2) << "前两次输出 " << i;
    LOG_IF_EVERY_N(WARNING, 1 < 2, 2) << "条件输出+频率" << google::COUNTER;
  }

  CHECK_EQ(1,1)<<"SHOULD EQ"<<std::endl;
  google::ShutdownGoogleLogging();
  google::ShutDownCommandLineFlags();
}