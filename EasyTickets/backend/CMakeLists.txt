cmake_minimum_required(VERSION 3.23)
project(Backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CONTROLLERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/controllers)
set(MODELS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/models)

file(GLOB SRC_FILES ${SRC_DIR}/*.cpp)

add_executable(backend ${SRC_FILES})

find_package(Drogon REQUIRED)
target_link_libraries(backend PRIVATE Drogon::Drogon)

add_subdirectory(${CONTROLLERS_DIR})
add_subdirectory(${MODELS_DIR})

target_include_directories(backend PRIVATE ${SRC_DIR} ${CONTROLLERS_DIR} ${MODELS_DIR})

target_link_libraries(backend PRIVATE controllers models)
