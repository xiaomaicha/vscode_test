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
  Mat frame;
  cout << "Opening camera..." << endl;
  VideoCapture capture(0); // open the first camera
  if (!capture.isOpened())
  {
    cerr << "ERROR: Can't initialize camera capture" << endl;
    return 1;
  }


  //【2】循环显示每一帧
  int j=0;

//  capture.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
//  capture.set(CV_CAP_PROP_FRAME_HEIGHT,720);
  while(1)
  {   clock_t start,finish;
    start=clock();
    j++;

    capture>>frame;  //读取当前帧
    if (frame.empty())
    {
      cerr << "ERROR: Can't grab camera frame." << endl;
      break;
    }
    imshow("读取视频",frame);  //显示当前帧
    cout<<frame.size()<<endl;
//    imwrite("1.jpg",frame);
    finish=clock();

    cout << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl;
    waitKey(1);  //延时30ms
  }
  return 0;
}