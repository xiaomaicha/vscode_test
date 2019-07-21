//
// Created by wuqi on 19-7-9.
//

//#include <iostream>
//#include <vector>
//#include <assert.h>
//
//#include <opencv2/xfeatures2d.hpp>
//#include <opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//
//  Mat img = imread("../../opencv_test/img1.png",cv::IMREAD_COLOR);
//  CV_Assert_1(!img.empty());
//  Ptr<Feature2D> sift = xfeatures2d::SIFT::create();
//  vector<cv::KeyPoint> keypoints;
//  Mat descriptors;
//
//  sift->detectAndCompute(img, cv::noArray(),keypoints, descriptors);
//  cv::drawKeypoints(img,keypoints,descriptors,cv::Scalar(0, 255, 255));
//  imshow("Result", descriptors);
//
//  waitKey();
//  return 0;
//}


#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
  int channels[3] = {0};
  cv::Mat srcImage = cv::Mat(240,320,CV_8UC3,cv::Scalar(75,125,225));
  //直接访问
  for (int y=0;y<10;y++)
  {
    for (int x=0;x<10;x++)
    {
      channels[0] = srcImage.at<cv::Vec3b>(y,x)[0];
      channels[1] = srcImage.at<cv::Vec3b>(y,x)[1];
      channels[2] = srcImage.at<cv::Vec3b>(y,x)[2];
      std::cout << "[";
      std::cout << channels[0] << ",";
      std::cout << channels[1] << ",";
      std::cout << channels[2] << "] ";
    }
  }
  //迭代器
  //遍历灰度图
  cv::imshow("主窗口", srcImage);
  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}
