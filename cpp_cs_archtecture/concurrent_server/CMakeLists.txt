include_directories(.)

add_executable(clent_main clent_main.cpp cpp_concurrent_client.cpp)
add_executable(server_main server_main.cpp cPP_concurrent_server.cpp)