#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
  
//使用cv这个命名空间  
using namespace cv;  
using namespace std;  
  
/*    主函数 
 *C语言规定main函数只能有两个参数， 
 *习惯上将这两个参数写成argc和argv。 
 *第一个代表(传参个数+1)， 
 *第二个代表传惨数据。 
 *一般有两种写法： 
 *main( int argc, char* argv[]) 
 *main( int argc, char** argv) 
 */  
int main( int argc, char** argv )  
{  
  //建立一个Mat类型的变量image  
  cv::Mat image;  
  /* API中有： 
   * C++: Mat imread(const string& filename, int flags=1 ) 
   * 意思是返回Mat类型数据，第一个参数接受一个string类型的引用， 
   * 第二个参数接受一个int类型的flags，一般都是1。 
   */  
  image = cv::imread( "img1.png",0);
  

  if( !image.data )  
    {  
      std::cout<<"no image"<<std::endl;

    }  
    std::cout<<"image channels:"<<image.channels()<<std::endl;
    std::cout<<"image1 size:"<<image.rows<<"*"<<image.cols<<std::endl;
  
  //当传的参数不是一个，或者图片没有数据则提示没有图片并退出程序  

  //C++: void namedWindow(const string& winname, int flags=CV_WINDOW_AUTOSIZE )  
  cv::namedWindow( "image" );  // CV_WINDOW_NORMAL
  //C++: void imshow(const string& winname, InputArray mat)  
  cv::imshow( "image", image ); 

  std::vector<float> V;
  V.assign ( ( float* )image.datastart, ( float* )image.dataend );
  
//   std::cout << "Vector" << std::endl;
// for ( int i = 0; i <image.rows * image.cols; ++i )
// {
//     std::cout << V[i] << std::endl;
// }
Mat image2=Mat(image.rows ,image.cols,CV_32FC1);
memcpy(image2.data,V.data(),V.size()*sizeof(float));
std::cout<<"image2 size:"<<image2.rows<<"*"<<image2.cols<<std::endl;

// std::cout << "Second matrix" << std::endl;
// std::cout << image2 <<std::endl;
   

  cv::namedWindow( "image2",  CV_WINDOW_NORMAL );  // CV_WINDOW_NORMAL
  cv::imwrite("/home/wuqi/img2.png",image2);
  //C++: void imshow(const string& winname, InputArray mat)  
  cv::imshow( "image2", image2 );

//  cv::calcOpticalFlowPyrLK();

  //C++: int waitKey(int delay=0)  
  waitKey(0);
  
  return 0;  
} 
