cmake_minimum_required(VERSION 3.23)
project(Controllers)

set(CONTROLLERS_SRC ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB CONTROLLERS_FILES ${CONTROLLERS_SRC}/*.cpp)

# Создаём статическую библиотеку с контроллерами
add_library(controllers STATIC ${CONTROLLERS_FILES})

# Добавляем include-директорию
target_include_directories(controllers PUBLIC ${CONTROLLERS_SRC})
