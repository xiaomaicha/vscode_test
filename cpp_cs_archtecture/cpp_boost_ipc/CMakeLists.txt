set(BOOST_ROOT /usr)
find_package(Boost REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
  MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
  MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
endif()

#add_executable(cpp_boost_shared_memory cpp_boost_shared_memory.cpp)
#target_link_libraries(cpp_boost_shared_memory ${Boost_LIBRARIES} -lrt)

INCLUDE_DIRECTORIES(.)

file(GLOB CPP_FILES *.cpp)

foreach (SAMPLE_SOURCE ${CPP_FILES})
  #  message(SATTUS "SOURCE: " ${SAMPLE_SOURCE})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" SAMPLE_NAME ${SAMPLE_SOURCE})
  add_executable(${SAMPLE_NAME} ${SAMPLE_SOURCE})
  target_link_libraries(${SAMPLE_NAME} ${Boost_LIBRARIES} -lrt)
endforeach (SAMPLE_SOURCE ${CPP_FILES})
