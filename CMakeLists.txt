cmake_minimum_required(VERSION 3.10)
project(homework5 C)

# Предупреждения
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_subdirectory(src)

# Главная программа
add_executable(homework5 sortStationMain.c)
target_link_libraries(homework5 sortStationLib stackLib)
