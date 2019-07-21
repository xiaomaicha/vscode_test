project(opengl_test)

## 支持C++11
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -O2 -std=c11")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g -Wall -O2 -std=c++11")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

FILE(GLOB samples ${PROJECT_SOURCE_DIR}/*.cpp)

FOREACH (sample ${samples})
  STRING(REGEX MATCH "[^/]+$" sample_file ${sample})
  STRING(REPLACE ".cpp" "" sample_basename ${sample_file})
  ADD_EXECUTABLE(test_${sample_basename} ${sample})
  TARGET_LINK_LIBRARIES(test_${sample_basename} ${OpenCV_LIBS} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} pthread)
ENDFOREACH()
