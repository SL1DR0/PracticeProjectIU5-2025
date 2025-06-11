
cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(JSONCPP_INCLUDE_DIR "/usr/include/jsoncpp")
set(JSONCPP_LIBRARY "/usr/lib/x86_64-linux-gnu/libjsoncpp.so")
set(JSONCPP_LIBRARIES ${JSONCPP_LIBRARY})
# Ручное подключение заголовков и библиотеки

project(FlightBookingAPI)
configure_file(${PROJECT_SOURCE_DIR}/config.json ${CMAKE_CURRENT_BINARY_DIR}/config.json COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/index.html ${CMAKE_CURRENT_BINARY_DIR}/index.html COPYONLY)
file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(DROGON_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/third_party/drogon_installed/usr/local)
find_package(Drogon REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указать исходные файлы
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/controllers/*.cpp"
)

# Добавить исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Подключить include директории
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/controllers
    ${PROJECT_SOURCE_DIR}/models
    ${Drogon_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Drogon::Drogon
    /usr/lib/x86_64-linux-gnu/libjsoncpp.so.1.9.5
)
