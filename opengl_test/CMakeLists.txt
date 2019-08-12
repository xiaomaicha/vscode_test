project(opengl_test)
# 查找OpenGL
FIND_PACKAGE(OpenGL REQUIRED)
IF(OPENGL_FOUND)
  MESSAGE("===== support OpenGL =====")
  MESSAGE(STATUS "OpenGL library status:")
  MESSAGE(STATUS "	include path: ${OPENGL_INCLUDE_DIR}")
  MESSAGE(STATUS "	libraries: ${OPENGL_LIBRARIES}")
  MESSAGE(STATUS "	version: ${OPENGL_VERSION}")
  INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
ELSE()
  MESSAGE("##### not support OpenGL #####")
ENDIF()

# 查找GLUT
FIND_PACKAGE(GLUT REQUIRED)
IF(GLUT_FOUND)
  MESSAGE("===== support GLUT =====")
  MESSAGE(STATUS "	include path: ${GLUT_INCLUDE_DIR}")
  MESSAGE(STATUS "	libraries: ${GLUT_LIBRARIES}")
  INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})
ELSE()
  MESSAGE("##### not support GLUT #####")
ENDIF()

find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")
INCLUDE_DIRECTORIES(${GLFW3_INCLUDE_DIR})

## 支持C++11
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -O2 -std=c11")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g -Wall -O2 -std=c++11")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

FILE(GLOB samples ${PROJECT_SOURCE_DIR}/*.cpp)

FOREACH (sample ${samples})
  STRING(REGEX MATCH "[^/]+$" sample_file ${sample})
  STRING(REPLACE ".cpp" "" sample_basename ${sample_file})
  ADD_EXECUTABLE(test_${sample_basename} ${sample})
  TARGET_LINK_LIBRARIES(test_${sample_basename} ${OpenCV_LIBS} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw pthread)
ENDFOREACH()
