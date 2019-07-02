cmake_minimum_required(VERSION 2.8)

project (json)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/include/json.hpp ${PROJECT_SOURCE_DIR}/src/json.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
