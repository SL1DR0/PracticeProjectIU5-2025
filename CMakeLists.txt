cmake_minimum_required(VERSION 3.10)
project(EasyTickets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Указываем пути для UIC
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Явно указываем include директории
include_directories(
    ${CMAKE_BINARY_DIR}/EasyTickets_autogen/include
    ${CMAKE_SOURCE_DIR}/src
)

set(SOURCES
    src/main.cpp
    src/mainWindow.cpp
    src/mainWindow.h
    src/secondWindow.cpp
    src/secondWindow.h
    ui/mainWindow.ui
    ui/secondWindow.ui
)

add_executable(EasyTickets ${SOURCES})
target_link_libraries(EasyTickets Qt5::Widgets)
