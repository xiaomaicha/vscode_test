//writed by zhang ning 2018/3/5 20:11
//本程序用来求解位姿变换问题
#include <iostream>
#include <cmath>
using namespace std;

#include "Eigen/Core"
#include "Eigen/Dense"
// Eigen 几何模块
#include "Eigen/Geometry"
//下面这段程序是用变换矩阵来计算的，可以得到相同的计算结果

int main( int argc, char** argv)
{
  Eigen::Vector3d p1,t1,t2;
  p1 << 0.5,-0.1,0.2;
  t1 << 0.7,1.1,0.2;
  t2 << -0.1,0.4,0.8;
  Eigen::Quaterniond q1 = Eigen::Quaterniond(0.55,0.3,0.2,0.2).normalized();
  
  Eigen::Isometry3d T1 = Eigen::Isometry3d::Identity();
  T1.rotate ( q1 );
  T1.pretranslate ( t1 );
  cout << "Transform matrix = \n" << T1.matrix() << endl;

  Eigen::Quaterniond q2 = Eigen::Quaterniond(-0.1,0.3,-0.7,0.2).normalized();

  Eigen::Isometry3d T2 = Eigen::Isometry3d::Identity();
  T2.rotate ( q2 );
  T2.pretranslate ( t2 );
  cout << "Transform matrix = \n" << T2.matrix() << endl;
  
  Eigen::Vector3d p2 = T2*T1.inverse()*p1;
  cout << p2 << endl;
  
  return 0;
}