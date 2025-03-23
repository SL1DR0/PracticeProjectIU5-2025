cmake_minimum_required(VERSION 3.14)
project(QtRegistrationApp)

# Включаем автоматическую генерацию MOC, UIC и RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Ищем Qt 5
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Исходные файлы
set(SOURCES
    main.cpp
)

# .ui файл
set(UI_FILES
    registration_form.ui
)

# Создаем исполняемый файл
add_executable(QtRegistrationApp ${SOURCES} ${UI_FILES})

# Подключаем библиотеки Qt 5
target_link_libraries(QtRegistrationApp PRIVATE Qt5::Widgets)
