cmake_minimum_required(VERSION 3.10)
project(Homework6.2 C)

# Предупреждения
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Где искать заголовки
include_directories(include)

# Создаем исполняемый файл
add_executable(homework6
    src/main.c
    src/counting.c
    src/josephus.c
    src/list.c
)
