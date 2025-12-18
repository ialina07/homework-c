cmake_minimum_required(VERSION 3.10)
project(CProgrammingTasks homework6.2)

# Включаем предупреждения
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Создаем исполняемый файл
add_executable(sortedList src/sortedList.c)
