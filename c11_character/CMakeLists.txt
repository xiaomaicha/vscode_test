INCLUDE_DIRECTORIES(.)

add_executable(std_thread_pool std_thread_pool.cpp)
target_link_libraries(std_thread_pool
        pthread
        )
add_executable(condition_var condition_var.cpp)
target_link_libraries(condition_var
        pthread
        )

add_executable(unique_lock unique_lock.cpp)
target_link_libraries(unique_lock
        pthread)

add_executable(std_mutex std_mutex.cpp)
target_link_libraries(std_mutex
        pthread
        )
add_executable(std_time_mutex std_time_mutex.cpp)
target_link_libraries(std_time_mutex
        pthread
        )
add_executable(std_sync_quene std_sync_quene.cpp)
target_link_libraries(std_sync_quene
        pthread
        )

add_executable(std_async std_async.cpp)
target_link_libraries(std_async
        pthread
        )

add_executable(std_assert std_assert.cpp)

add_executable(std_move std_move.cpp)

add_executable(std_bind std_bind.cpp)
add_executable(std_function std_function.cpp)

add_executable(initializer_list initializer_list.cpp)

add_executable(std_vector_new std_vector_new.cpp)

add_executable(std_unique_ptr std_unique_ptr.cpp)

add_executable(std_add_remove_ref std_add_remove_ref.cpp)

add_executable(std_changeable_args std_changeable_args.cpp)

add_executable(std_optional std_optional.cpp)