////
//// Created by wuqi on 19-6-20.
////
//
//#include <iostream>
//
//
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//
//int main(int argc,char* argv[])
//
//{
//  cv::VideoCapture capture(argv[1]);
//  if(!capture.isOpened())
//
//  {
//    std::cout<<"video not open."<<std::endl;
//    return 1;
//  }
//  //获取当前视频帧率
//  double rate = capture.get(CV_CAP_PROP_FPS);
//  //当前视频帧
//  cv::Mat frame;
//  //每一帧之间的延时
//  //与视频的帧率相对应
//  int delay = 1000/rate;
//  bool stop(false);
//  while(!stop)
//
//  {
//    if(!capture.read(frame))
//
//    {
//      std::cout<<"no video frame"<<std::endl;
//      break;
//    }
//
//    //此处为添加对视频的每一帧的操作方法
//    int frame_num = capture.get(CV_CAP_PROP_POS_FRAMES);
//    std::cout<<"Frame Num : "<<frame_num<<std::endl;
////    if(frame_num==20)
////
////    {
////      capture.set(CV_CAP_PROP_POS_FRAMES,10);
////    }
//
//    cv::imshow("video",frame);
//    //引入延时
//    //也可通过按键停止
//    if(cv::waitKey(delay)>0)
//      stop = true;
//  }
//
//
//  //关闭视频，手动调用析构函数（非必须）
//  capture.release();
//  return 0;
//}
//

#include <opencv2/core/core.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>  // cv::Canny()
#include <opencv2/imgproc/imgproc.hpp>  // cv::Canny()

#include <iostream>

using namespace cv;
using std::cout; using std::cerr; using std::endl;

int main(int, char**)
{
  Mat frame;
  cout << "Opening camera..." << endl;
  VideoCapture capture(0); // open the first camera
  if (!capture.isOpened())
  {
    cerr << "ERROR: Can't initialize camera capture" << endl;
    return 1;
  }

  cout << "Frame width: " << capture.get(CV_CAP_PROP_FRAME_WIDTH) << endl;
  cout << "     height: " << capture.get(CV_CAP_PROP_FRAME_HEIGHT) << endl;
  cout << "Capturing FPS: " << capture.get(CV_CAP_PROP_FPS) << endl;

  cout << endl << "Press 'ESC' to quit, 'space' to toggle frame processing" << endl;
  cout << endl << "Start grabbing..." << endl;

  size_t nFrames = 0;
  bool enableProcessing = false;
  int64 t0 = cv::getTickCount();
  int64 processingTime = 0;
  for (;;)
  {
    capture >> frame; // read the next frame from camera
    if (frame.empty())
    {
      cerr << "ERROR: Can't grab camera frame." << endl;
      break;
    }
    nFrames++;
    if (nFrames % 10 == 0)
    {
      const int N = 10;
      int64 t1 = cv::getTickCount();
      cout << "Frames captured: " << cv::format("%5lld", (long long int)nFrames)
           << "    Average FPS: " << cv::format("%9.1f", (double)getTickFrequency() * N / (t1 - t0))
           << "    Average time per frame: " << cv::format("%9.2f ms", (double)(t1 - t0) * 1000.0f / (N * getTickFrequency()))
           << "    Average processing time: " << cv::format("%9.2f ms", (double)(processingTime) * 1000.0f / (N * getTickFrequency()))
           << std::endl;
      t0 = t1;
      processingTime = 0;
    }
    if (!enableProcessing)
    {
      imshow("Frame", frame);
    }
    else
    {
      int64 tp0 = cv::getTickCount();
      Mat processed;
      cv::Canny(frame, processed, 400, 1000, 5);
      processingTime += cv::getTickCount() - tp0;
      imshow("Frame", processed);
    }
    int key = waitKey(1);
    if (key == 27/*ESC*/)
      break;
    if (key == 32/*SPACE*/)
    {
      enableProcessing = !enableProcessing;
      cout << "Enable frame processing ('space' key): " << enableProcessing << endl;
    }
  }
  std::cout << "Number of captured frames: " << nFrames << endl;
  return nFrames > 0 ? 0 : 1;
}
