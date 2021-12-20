cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c
        )
add_library(library ${SOURCE_LIB})
add_library(io_lib STATIC library/io.c)
add_library(array_lib STATIC library/array.c)
add_library(LinkedMap STATIC library/LinkedMap.c)
add_library(String STATIC library/String.c)
add_library(Binary STATIC library/Binary.c)
add_library(List STATIC library/list.c)

add_library(Values STATIC library/values/values.c)
add_library(ArrayList STATIC library/list/arrayList.c)
target_link_libraries(ArrayList Values)
add_library(TreeMap STATIC library/TreeMap.c)
target_link_libraries(TreeMap Values library)
add_library(DFA STATIC library/DFA.c)
add_library(ComplexNumber STATIC library/ComplexNumber.c)
target_link_libraries(ComplexNumber m)

add_executable(HW1_Task_1 homework1/task_1.c)
target_link_libraries(HW1_Task_1 io_lib)

add_executable(HW1_Task_2 homework1/task_2.c)
target_link_libraries(HW1_Task_2 io_lib array_lib)

add_executable(HW1_Task_3 homework1/task_3.c)
target_link_libraries(HW1_Task_3 io_lib array_lib)

add_executable(HW1_Task_4 homework1/task_4.c)
target_link_libraries(HW1_Task_4 io_lib array_lib)

add_executable(HW1_Task_5 homework1/task_5.c)
target_link_libraries(HW1_Task_5 io_lib)

add_executable(HW2_Task_1 homework2/task_1.c)
target_link_libraries(HW2_Task_1 io_lib LinkedMap)

add_executable(HW2_Task_2 homework2/task_2.c)
target_link_libraries(HW2_Task_2 String io_lib)

add_executable(HW3_Task_1 homework3/task_1.c)
target_link_libraries(HW3_Task_1 Binary io_lib)

add_executable(HW3_Task_2 homework3/task_2.c)

add_executable(HW3_Task_3 homework3/task_3.c)
target_link_libraries(HW3_Task_3 Binary io_lib)

add_executable(Test1_task1 test1/task1.c)
target_link_libraries(Test1_task1 io_lib m)

add_executable(Test1_task2 test1/task2.c)
target_link_libraries(Test1_task2 List io_lib m)

add_executable(Test2_task1 test2/task_1.c)
target_link_libraries(Test2_task1 io_lib)

add_executable(HW5_Task_1 homework5/task_1.c)
target_link_libraries(HW5_Task_1 TreeMap io_lib)

add_executable(Test2_task2 test2/task2.c)
target_link_libraries(Test2_task2 io_lib)

add_executable(Test2_task3 test2/task3.c)
target_link_libraries(Test2_task3 io_lib)

add_executable(HW8_task homework8/task.c)
target_link_libraries(HW8_task DFA)

add_executable(Retest1_task1 retest1/task1.c)
target_link_libraries(Retest1_task1 ComplexNumber)