add_executable(config_test main1.cpp)
add_executable(boost_test1 boost_sig2_test.cpp)
add_executable(boost_test2 boost_sig2_test2.cpp)
add_executable(thread_test1 thread_test1.cpp)
target_link_libraries(thread_test1
  pthread
)
add_executable(thread_test2 thread_test2.cpp)
target_link_libraries(thread_test2
  pthread
)

add_executable(eigen_geometry_test1 eigen_geometry_test1.cpp)
target_link_libraries(eigen_geometry_test1
  ${EIGEN3_LIBRARIES}
)

add_executable(eigen_geometry_test2 eigen_geometry_test2.cpp)
target_link_libraries(eigen_geometry_test2
  ${EIGEN3_LIBRARIES}
)

ADD_EXECUTABLE( opencv_test1 opencv_test1.cpp )
TARGET_LINK_LIBRARIES( opencv_test1 
    ${OpenCV_LIBS} )

add_executable(io_test1 io_test1.cpp)
