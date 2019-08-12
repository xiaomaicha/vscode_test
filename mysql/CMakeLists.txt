#find_package(mysql REQUIRED)
#IF (mysql_FOUND)
#  message(STATUS "FOUND MYSQL")
#ELSEIF ()
#  message(STATUS "NOT FOUND MYSQL")
#ENDIF ()

add_executable(mysql_test1 mysql_test1.cpp)
target_link_libraries(mysql_test1 mysqlclient)