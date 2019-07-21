project(addressbook)
AUX_SOURCE_DIRECTORY(. SRC_LIST)
FOREACH (F ${SRC_LIST})
  MESSAGE(STATUS "SRC: " ${F})
ENDFOREACH (F ${SRC_LIST})

add_library(${PROJECT_NAME} SHARED ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} PUBLIC protobuf)

include_directories(.)
add_subdirectory(addressbook_sample)