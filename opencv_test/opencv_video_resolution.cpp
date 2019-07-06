//
// Created by wuqi on 19-7-3.
//

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include<ctime>
using namespace cv;
using namespace std;

int main( )
{
  //【1】从摄像头读入视频
  VideoCapture capture(1);
  if(!capture.isOpened())

  {
    std::cout<<"video not open."<<std::endl;
    return 1;
  }

  //【2】循环显示每一帧
  int j=0;

  capture.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
  capture.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
  while(1)
  {   clock_t start,finish;
    start=clock();
    j++;
    Mat frame;  //定义一个Mat变量，用于存储每一帧的图像
    capture>>frame;  //读取当前帧
    imshow("读取视频",frame);  //显示当前帧
    cout<<frame.size()<<endl;
//    imwrite("1.jpg",frame);
    finish=clock();

    cout << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl;
    waitKey(1);  //延时30ms
  }
  return 0;
}