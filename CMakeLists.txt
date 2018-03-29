cmake_minimum_required(VERSION 2.8.3)
project(vs_test)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )

set(PTHREAD_LIB "")
find_package(Threads)
if(CMAKE_THREAD_LIBS_INIT)
  string(LENGTH ${CMAKE_THREAD_LIBS_INIT} _length)
  if(_length GREATER 2)
    string(SUBSTRING ${CMAKE_THREAD_LIBS_INIT} 0 2 _prefix)
    if(${_prefix} STREQUAL "-l")
      math(EXPR _rest_len "${_length} - 2")
      string(SUBSTRING ${CMAKE_THREAD_LIBS_INIT} 2 ${_rest_len} PTHREAD_LIB)
    endif()
  endif()
endif() 

#opencv
find_package(OpenCV 2 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories( ${OpenCV_LIBRARY_DIRS})
message(${OpenCV_INCLUDE_DIRS} )

#Eigen
find_package(Eigen3 REQUIRED)
set(Eigen3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen3_LIBRARIES ${EIGEN3_LIBRARIES})
message(${EIGEN3_INCLUDE_DIRS} )
include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(config_test src/main1.cpp)
add_executable(boost_test1 src/boost_sig2_test.cpp)
add_executable(boost_test2 src/boost_sig2_test2.cpp)
add_executable(thread_test1 src/thread_test1.cpp)
target_link_libraries(thread_test1
  ${PTHREAD_LIB}
)
add_executable(thread_test2 src/thread_test2.cpp)
target_link_libraries(thread_test2
  ${PTHREAD_LIB}
)

add_executable(eigen_geometry_test1 src/eigen_geometry_test1.cpp)
target_link_libraries(eigen_geometry_test1
  ${EIGEN3_LIBRARIES}
)

add_executable(eigen_geometry_test2 src/eigen_geometry_test2.cpp)
target_link_libraries(eigen_geometry_test2
  ${EIGEN3_LIBRARIES}
)

ADD_EXECUTABLE( opencv_test1 src/opencv_test1.cpp )
TARGET_LINK_LIBRARIES( opencv_test1 
    ${OpenCV_LIBS} )

add_executable(io_test1 src/io_test1.cpp)


