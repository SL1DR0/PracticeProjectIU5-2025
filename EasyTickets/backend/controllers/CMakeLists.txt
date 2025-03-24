cmake_minimum_required(VERSION 3.23)
project(Models)

set(MODELS_SRC ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB MODELS_FILES ${MODELS_SRC}/*.cpp)

# Создаём статическую библиотеку с моделями
add_library(models STATIC ${MODELS_FILES})

# Добавляем include-директорию
target_include_directories(models PUBLIC ${MODELS_SRC})
