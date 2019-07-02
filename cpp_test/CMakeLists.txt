add_definitions(-D__Debug_mode=2)

#add_executable(eigen_geometry_test1 eigen_geometry_test1.cpp)
#add_executable(eigen_geometry_test2 eigen_geometry_test2.cpp)
#add_executable(config_test main1.cpp)
#add_executable(boost_test1 boost_sig2_test.cpp)
#add_executable(boost_test2 boost_sig2_test2.cpp)
#add_executable(io_test1 io_test1.cpp)
#add_executable(get_ip get_ip.cpp)
#add_executable(get_folder_filenname get_folder_filenname.cpp)
#add_executable(read_txtfile read_txtfile.cpp)
#add_executable(write_csv write_csv.cpp)
#
#add_executable(stl_macro stl_macro.cpp)
#add_executable(callable_object callable_object.cpp)
#add_executable(create_multidir create_multidir.cpp)
#add_executable(linux_dir_operation linux_dir_operation.cpp)
#add_executable(output_json output_json.cpp)
#target_link_libraries(output_json json)

INCLUDE_DIRECTORIES(.)

file(GLOB CPP_FILES *.cpp)

foreach (SAMPLE_SOURCE ${CPP_FILES})
  #  message(SATTUS "SOURCE: " ${SAMPLE_SOURCE})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" SAMPLE_NAME ${SAMPLE_SOURCE})
  add_executable(${SAMPLE_NAME} ${SAMPLE_SOURCE})
  target_link_libraries(${SAMPLE_NAME} json)
endforeach (SAMPLE_SOURCE ${CPP_FILES})


