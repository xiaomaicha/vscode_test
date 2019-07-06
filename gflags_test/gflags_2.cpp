//
// Created by wuqi on 19-7-6.
//

//gflags的参数是从-arg中读出来的，如果没有只是加了一个参数，是不会被gflags解析的

#include <iostream>
#include <gflags/gflags.h>

using namespace std;

DEFINE_string(confPath, "../conf/setup.ini", "program configure file.");
DEFINE_int32(port, 9090, "program listen port");
DEFINE_bool(daemon, false, "run daemon mode");

int main(int argc, char** argv)
{
  gflags::SetVersionString("1.0.0.0");
  gflags::SetUsageMessage("Usage : ./demo ");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  cout << "confPath = " << FLAGS_confPath << endl;
  cout << "port = " << FLAGS_port << endl;

  if (FLAGS_daemon) {
    cout << "run background ..." << endl;
  }
  else {
    cout << "run foreground ..." << endl;
  }

  cout << "good luck and good bye!" << endl;

//  cout<<argc<<" "<<argv[1]<<endl;

  gflags::ShutDownCommandLineFlags();
  return 0;
}