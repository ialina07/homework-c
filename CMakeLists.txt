cmake_minimum_required(VERSION 3.10)
project(homework12.1 C)

# Предупреждения
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Где искать заголовки
include_directories(include)

# Библиотека с функциями 
add_library(dv_lib src/homework12.1_01.12_binaryRepresentation/dv.c)

# Главная программа 
add_executable(dv_program src/homework12.1_01.12_binaryRepresentation/main.c)
target_link_libraries(dv_program dv_lib)

# Тесты 
add_executable(dv_tests tests/homework12.1/testsBinaryRepresentation.c)
target_link_libraries(dv_tests dv_lib)
