//writed by zhang ning 2018/3/5 20:11
//本程序用来求解位姿变换问题
#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>
// Eigen 几何模块
#include <Eigen/Geometry>

int main( int argc, char** argv)
{
  Eigen::Vector3d p1,t1,t2;
  p1 << 0.5,-0.1,0.2;
  t1 << 0.7,1.1,0.2;
  t2 << -0.1,0.4,0.8;
// 四元数Eigen::Quaterniond 的正确初始化顺序为Eigen::Quaterniond(w,x,y,z)
// 而 coeffs的顺序是（x,y,z,w）,w 为实部，前三者为虚部 
// 因为要表示相反的旋转，故输入为q1的共轭，即实部不变，虚部变为相反数
  Eigen::Quaterniond q1 = Eigen::Quaterniond(0.55,-0.3,-0.2,-0.2).normalized();
  cout << q1.coeffs().transpose() << endl;


  Eigen::Quaterniond q2 = Eigen::Quaterniond(-0.1,0.3,-0.7,0.2).normalized();
  cout << q2.coeffs().transpose() << endl;
  
  Eigen::Vector3d pw = q1*(p1-t1);  //数学上是qpq-1
  Eigen::Vector3d p2 = q2*pw + t2;

  cout << p2 << endl;
  
  return 0;
}