## setup CUDA
#find_package(CUDA)
#
## 指定CUDA头文件的搜索路径
#include_directories(${CUDA_INCLUDE_DIRS})
#message(STATUS "CUDA LIB:" ${CUDA_LIBRARIES})
#
## 使CUDA NVCC 编译器支持C++11特性
#LIST(APPEND CUDA_NVCC_FLAGS -std=c++11;-O2)
#LIST(APPEND CUDA_NVCC_FLAGS -Xcompiler;-fPIC)
#
#LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_35,code=sm_35)
#LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_53,code=sm_53)
#LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_61,code=sm_61)
#LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_62,code=sm_62)
#
#file(GLOB CPP_FILES *.cpp)
#
#foreach (SAMPLE_SOURCE ${CPP_FILES})
#  #  message(SATTUS "SOURCE: " ${SAMPLE_SOURCE})
#  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" SAMPLE_NAME ${SAMPLE_SOURCE})
#  CUDA_ADD_EXECUTABLE(${SAMPLE_NAME} ${SAMPLE_SOURCE})
#  target_link_libraries(${SAMPLE_NAME} cublas)
#endforeach (SAMPLE_SOURCE ${CPP_FILES})