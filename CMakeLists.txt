cmake_minimum_required(VERSION 3.10)
project(homework10 C)

# Предупреждения
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Где искать заголовки
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(sortedlist src/homework6.1_28.10_sortedList/sortedList.c)

# Тесты (главная программа)
add_executable(run_tests tests/homework10/testSortedList.c)
target_link_libraries(run_tests sortedlist)
