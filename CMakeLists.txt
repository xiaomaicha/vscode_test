cmake_minimum_required(VERSION 2.8.3)
project(vs_test)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g")

# Select flags.
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -ggdb -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG  "-O0 -ggdb")

#add_compile_options(-static-libstdc++)
#add_compile_options(-fvisibility=hidden)
add_compile_options(-fPIC)
add_compile_options(-Wno-dev)
add_compile_options(-Wall)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
set( LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")


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


#find_package(PkgConfig)
#pkg_check_modules(OpenCV opencv)

#list(APPEND OPENCV_MODULE_LIST calib3d contrib core features2d flann gpu)
#list(APPEND OPENCV_MODULE_LIST highgui imgproc legacy ml objdetect ocl)
#list(APPEND OPENCV_MODULE_LIST photo stitching superres ts video videostab)
#list(APPEND OPENCV_MODULE_LIST cudaarithm cudabgsegm cudacodec cudafeatures2d)
#list(APPEND OPENCV_MODULE_LIST cudafilters cudaimgproc cudalegacy cudaobjdetect)
#list(APPEND OPENCV_MODULE_LIST cudaoptflow cudastereo cudawarping cudev)
#list(APPEND OPENCV_MODULE_LIST imgcodecs shape videoio)

##add_library(opencv_system_runtime INTERFACE)
##set(OpenCV_DIR "/usr/local/opencv3/share/OpenCV")
#find_package(OpenCV 2 REQUIRED)
#include_directories( ${OpenCV_INCLUDE_DIRS} )
#link_directories(${OpenCV_LIBRARY_DIRS})
#message(STATUS "OPENCV INCLUDE_DIR: " ${OpenCV_INCLUDE_DIRS} )
#message(STATUS "OpenCV_VERSION:: " ${OpenCV_VERSION})
#message(STATUS "OpenCV_DIR:: " ${OpenCV_DIR})
##foreach (OpenCV_LIB ${OpenCV_LIBS})
###  message(STATUS "opencv lib: " ${OpenCV_LIB})
##  find_library(${OpenCV_LIB}_MODULE ${OpenCV_LIB}  HINTS ${OPENCV_DIR})
##  message(STATUS "opencv lib: " ${${OpenCV_LIB}_MODULE})
##  target_link_libraries(opencv_system_runtime INTERFACE ${${OpenCV_LIB}_MODULE})
##endforeach ()

FIND_PACKAGE(OpenCV  REQUIRED)
IF(OpenCV_FOUND)
  MESSAGE("===== support OpenCV =====")
  MESSAGE(STATUS "OpenCV library status:")
  MESSAGE(STATUS "	version: ${OpenCV_VERSION}")
  MESSAGE(STATUS "	include path: ${OpenCV_INCLUDE_DIRS}")
  MESSAGE(STATUS "	install path: ${OpenCV_INSTALL_PATH}")
  MESSAGE(STATUS "	libraries: ${OpenCV_LIBS}")
  INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
ELSE()
  MESSAGE("##### not support OpenCV #####")
ENDIF()

# 查找OpenMP
FIND_PACKAGE(OpenMP REQUIRED)
IF(OpenMP_FOUND)
  MESSAGE("===== support OpenMP =====")
  MESSAGE(STATUS "OpenMP library status:")
  MESSAGE(STATUS "	version: ${OpenMP_VERSION}")
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
ELSE()
  MESSAGE("##### not support OpenMP #####")
ENDIF()



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
add_subdirectory(glog_test)
add_subdirectory(gflags_test)
add_subdirectory(linux_network_program)
add_subdirectory(opencv_test)
add_subdirectory(cpp_functon_test)
add_subdirectory(protobuf_test)
add_subdirectory(opengl_test)

add_subdirectory(cuda_test)
add_subdirectory(cpp_cs_archtecture)
add_subdirectory(cpp_stl)
add_subdirectory(mysql)



