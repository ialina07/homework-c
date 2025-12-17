cmake_minimum_required(VERSION 3.10)
project(double C)

# Предупреждения
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Где искать заголовки
include_directories(include)

# Библиотека с функциями
add_library(double_lib src/double.c)

# Главная программа
add_executable(double_program main.c)
target_link_libraries(double_program double_lib)

# Тесты
add_executable(double_tests tests/testsDouble.c)
target_link_libraries(double_tests double_lib)
