cmake_minimum_required(VERSION 3.10)
project(OptSort C)

# Предупреждения
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Где искать заголовки
include_directories(include)

# Главная программа
add_executable(optsort src/homework4_06.10_optSort/main.c src/homework4_06.10_optSort/optSort.c)
