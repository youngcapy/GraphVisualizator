cmake_minimum_required(VERSION 3.20)
project(SortVisualization)

# Указываем директории для заголовочных файлов
include_directories(headers)

# Указываем директорию для исходных файлов
set(SOURCE_DIR sources)

# Добавляем исполняемый файл
add_executable(SortVisualization ${SOURCE_DIR}/InfoOps.cpp ${SOURCE_DIR}/SortGui.cpp)