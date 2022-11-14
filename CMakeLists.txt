cmake_minimum_required(VERSION 3.14)

project(3Dcube VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(Qt5 REQUIRED COMPONENTS Core Widgets 3DCore 3DInput
                                     3DExtras 3DRender SerialPort)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

set(HEADER_FILES ${HEADER_DIR}/scenemodifier.hpp
                 ${HEADER_DIR}/inputdialog.hpp
                 ${HEADER_DIR}/serialport.hpp
                 ${HEADER_DIR}/parameters.hpp
                 ${HEADER_DIR}/mainwindow.hpp
                 ${HEADER_DIR}/modelloader.hpp)

set(SOURCE_FILES ${SOURCE_DIR}/main.cpp
                 ${SOURCE_DIR}/scenemodifier.cpp
                 ${SOURCE_DIR}/inputdialog.cpp
                 ${SOURCE_DIR}/serialport.cpp
                 ${SOURCE_DIR}/mainwindow.cpp
                 ${SOURCE_DIR}/modelloader.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE TRUE)

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_DIR})

target_link_libraries(${PROJECT_NAME} Qt::Core Qt::Widgets Qt::3DCore Qt::3DExtras
                                      Qt::3DRender Qt::3DInput Qt::SerialPort)
