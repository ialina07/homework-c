cmake_minimum_required(VERSION 3.10)
project(CProgrammingTasks C)

# Включаем предупреждения
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Создаем исполняемые файлы для каждой задачи
add_executable(task1 src/task1.c)
add_executable(task2 src/task2.c)
add_executable(task3 src/task3.c)
add_executable(task4 src/task4.c)
