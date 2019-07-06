## glog 如果四安装在/user中就不需要下面的语句
#find_package(Glog REQUIRED)
#include_directories(BEFORE ${GLOG_INCLUDE_DIRS})

file(GLOB CPP_FILES *.cpp)

foreach (SAMPLE_SOURCE ${CPP_FILES})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" SAMPLE_NAME ${SAMPLE_SOURCE})
  add_executable(${SAMPLE_NAME} ${SAMPLE_SOURCE})
  target_link_libraries(${SAMPLE_NAME} PRIVATE glog pthread)
endforeach (SAMPLE_SOURCE ${CPP_FILES})

