cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c
        )
add_library(library ${SOURCE_LIB})
add_library(io_lib STATIC library/io.c)
add_library(array_lib STATIC library/array.c)

add_executable(HW1_Task_1 homework1/task_1.c)
target_link_libraries(HW1_Task_1 io_lib)

add_executable(HW1_Task_3 homework1/task_3.c)
target_link_libraries(HW1_Task_3 io_lib array_lib)

add_executable(HW1_Task_5 homework1/task_5.c)
target_link_libraries(HW1_Task_5 io_lib)