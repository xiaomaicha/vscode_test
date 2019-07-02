cmake_minimum_required(VERSION 2.8.3)
project(vs_test)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g")
#add_compile_options(-Wno-dev)
#set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )

set(PTHREAD_LIB "")
find_package(Threads)
message("CMAKE_THREAD_LIBS_INIT: " ${CMAKE_THREAD_LIBS_INIT} )
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
find_package(OpenCV 3 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
#link_directories( ${OpenCV_LIBRARY_DIRS})
message(STATUS "OPENCV INCLUDE_DIR: " ${OpenCV_INCLUDE_DIRS} )
message(STATUS "OpenCV_VERSION:: " ${OpenCV_VERSION})
foreach (OpenCV_LIB ${OpenCV_LIBS})
  message(STATUS "opencv lib: " ${OpenCV_LIB})
endforeach ()

#Eigen
find_package(Eigen3 REQUIRED)
set(Eigen3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen3_LIBRARIES ${EIGEN3_LIBRARIES})
message(STATUS "Eigen3_INCLUDE_DIRS: " ${Eigen3_INCLUDE_DIRS})
include_directories(${Eigen3_INCLUDE_DIRS})

#gtest
add_subdirectory(thirdparty/googletest)
add_subdirectory(json)

add_subdirectory(c11_character)
add_subdirectory(c11_htread)
add_subdirectory(cpp_test)
add_subdirectory(gtest_test)
add_subdirectory(linux_network_program)
add_subdirectory(opencv_test)
add_subdirectory(cpp_functon_test)



