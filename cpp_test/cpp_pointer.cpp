//#include <stdio.h>
//#include <dirent.h>
//#include<iostream>
//int main(void) {
//  DIR *dirptr = nullptr;
//  dirent *entry;
//  dirptr = opendir("../");
//  if (dirptr == nullptr) {
//    std::cout << "open dir !" << std::endl;
//  } else {
//    entry = readdir(dirptr);
//    while (entry) {
//      std::cout << entry->d_name << std::endl;
//      //printf("%s\\n", entry->d_name);/* 打印出该目录下的所有内容 */
//      entry = readdir(dirptr);
//    }
//    closedir(dirptr);
//  }
//  return 0;
//}



#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

void bot_roll_pitch_yaw_to_quat(const double rpy[], double q[]) {
  double roll = rpy[0], pitch = rpy[1], yaw = rpy[2];

  double halfroll = roll / 2;
  double halfpitch = pitch / 2;
  double halfyaw = yaw / 2;

  double sin_r2 = sin(halfroll);
  double sin_p2 = sin(halfpitch);
  double sin_y2 = sin(halfyaw);

  double cos_r2 = cos(halfroll);
  double cos_p2 = cos(halfpitch);
  double cos_y2 = cos(halfyaw);

  q[0] = cos_r2 * cos_p2 * cos_y2 + sin_r2 * sin_p2 * sin_y2;  //w
  q[1] = sin_r2 * cos_p2 * cos_y2 - cos_r2 * sin_p2 * sin_y2;  //x
  q[2] = cos_r2 * sin_p2 * cos_y2 + sin_r2 * cos_p2 * sin_y2;  //y
  q[3] = cos_r2 * cos_p2 * sin_y2 - sin_r2 * sin_p2 * cos_y2;  //z
}

void operate_pointer(const double *pointer_a) {
  double fu = 2.1;
  pointer_a = &fu;
}

void operate_ref(double& ref_a){
  ref_a = 2.1;
}

int main() {
  double rpy_[3] = {3.1415 / 4, 0.0};
  double quat[4];
  bot_roll_pitch_yaw_to_quat(rpy_, quat);
  cout << "四元数\n" << quat[0] << "  " << quat[1] << "  " << quat[2] << "  " << quat[3] << endl;


  //指针与引用的区别
  double you = 1.0;
  auto *d_ptr = &you;
  cout << "size of ptr: " << sizeof(d_ptr) << endl;
  printf("%f\n", *d_ptr);
  operate_pointer(d_ptr);
  printf("%f\n", *d_ptr);

  printf("%f\n", you);
  operate_ref(you);
  printf("%f\n", you);

  double const *const_ptr = d_ptr;
  const_ptr++;
//    getchar();
  return 0;
}

