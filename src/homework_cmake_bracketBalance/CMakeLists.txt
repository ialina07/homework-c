# Библиотека для проверки скобок
add_library(bracketBalanceLib bracketBalance.c)

# Указываем пути к заголовочным файлам
target_include_directories(bracketBalanceLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Связываем с библиотекой стека
target_link_libraries(bracketBalanceLib PRIVATE stackLib)
