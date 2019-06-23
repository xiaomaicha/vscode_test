add_executable(eigen_geometry_test1 eigen_geometry_test1.cpp)
target_link_libraries(eigen_geometry_test1
  ${EIGEN3_LIBRARIES}
  )
add_executable(eigen_geometry_test2 eigen_geometry_test2.cpp)
target_link_libraries(eigen_geometry_test2
  ${EIGEN3_LIBRARIES}
  )
add_executable(config_test main1.cpp)
add_executable(boost_test1 boost_sig2_test.cpp)
add_executable(boost_test2 boost_sig2_test2.cpp)
add_executable(io_test1 io_test1.cpp)
add_executable(get_ip get_ip.cpp)
add_executable(get_folder_filenname get_folder_filenname.cpp)
add_executable(read_txtfile read_txtfile.cpp)
add_executable(write_csv write_csv.cpp)
add_compile_options(-D__Debug_mode)
add_executable(stl_macro stl_macro.cpp)
add_executable(callable_object callable_object.cpp)
add_executable(create_multidir create_multidir.cpp)
add_executable(linux_dir_operation linux_dir_operation.cpp)
