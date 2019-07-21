INCLUDE_DIRECTORIES(.)

file(GLOB CPP_FILES *.cpp)

foreach (SAMPLE_SOURCE ${CPP_FILES})
  #  message(SATTUS "SOURCE: " ${SAMPLE_SOURCE})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" SAMPLE_NAME ${SAMPLE_SOURCE})
  add_executable(${SAMPLE_NAME} ${SAMPLE_SOURCE})
endforeach (SAMPLE_SOURCE ${CPP_FILES})

add_subdirectory(concurrent_server)
add_subdirectory(cpp_ipc)
add_subdirectory(cpp_boost_ipc)