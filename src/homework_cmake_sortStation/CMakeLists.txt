# Библиотека сортировочной станции
add_library(sortStationLib sortStation.c)

# Указываем путь к заголовочным файлам
target_include_directories(sortStationLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Связываем библиотеки
target_link_libraries(sortStationLib PRIVATE stackLib)
