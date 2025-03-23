cmake_minimum_required(VERSION 3.14)
project(QtProject)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Добавьте папку сборки в список директорий для поиска заголовочных файлов
include_directories(${CMAKE_BINARY_DIR})

# Добавьте исходные файлы
set(SOURCES
    main.cpp
    mainWindow.cpp
    secondWindow.cpp
)

# Добавьте UI-файлы
set(FORMS
    mainWindow.ui
    secondWindow.ui
)

# Генерация UI-заголовочных файлов
qt5_wrap_ui(UI_HEADERS ${FORMS})

# Генерация MOC-файлов
qt5_wrap_cpp(MOC_SOURCES
    mainWindow.h
    secondWindow.h
)

# Создание исполняемого файла
add_executable(QtProject ${SOURCES} ${UI_HEADERS} ${MOC_SOURCES})

# Подключение библиотек Qt
target_link_libraries(QtProject Qt5::Widgets)
