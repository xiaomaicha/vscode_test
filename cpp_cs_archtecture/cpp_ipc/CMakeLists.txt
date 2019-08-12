add_executable(cpp_proc_pipe cpp_proc_pipe.cpp)

add_executable(cpp_fifo_read cpp_fifo_read.cpp)
add_executable(cpp_fifo_write cpp_fifo_write.cpp)
add_executable(cpp_signal cpp_signal.cpp)

add_executable(cpp_msg_send cpp_msg_send.cpp)
add_executable(cpp_msg_write cpp_msg_write.cpp)

add_executable(cpp_sem cpp_sem.cpp)
add_executable(cpp_sem2 cpp_sem2.cpp)
target_link_libraries(cpp_sem2 rt)