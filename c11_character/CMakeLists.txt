add_executable(std_thread std_thread.cpp)
target_link_libraries(std_thread
  pthread
)
add_executable(condition_var condition_var.cpp)
target_link_libraries(condition_var
  pthread
)

add_executable(unique_lock unique_lock.cpp)
target_link_libraries(unique_lock
pthread)

add_executable(std_assert std_assert.cpp)