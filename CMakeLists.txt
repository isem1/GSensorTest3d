cmake_minimum_required(VERSION 3.14)

include(cmake/utilities.cmake)
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

set(CXSOURCES_DIR ${PROJECT_SOURCE_DIR}/sources)

set(HEADER_FILES ${CXSOURCES_DIR}/scenemodifier.hpp
                 ${CXSOURCES_DIR}/inputdialog.hpp
                 ${CXSOURCES_DIR}/serialport.hpp
                 ${CXSOURCES_DIR}/parameters.hpp
                 ${CXSOURCES_DIR}/mainwindow.hpp
                 ${CXSOURCES_DIR}/modelloader.hpp)

set(SOURCE_FILES ${CXSOURCES_DIR}/main.cpp
                 ${CXSOURCES_DIR}/scenemodifier.cpp
                 ${CXSOURCES_DIR}/inputdialog.cpp
                 ${CXSOURCES_DIR}/serialport.cpp
                 ${CXSOURCES_DIR}/mainwindow.cpp
                 ${CXSOURCES_DIR}/modelloader.cpp)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
format_source_group(${SOURCE_FILES} ${HEADER_FILES})

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE TRUE)

target_link_libraries(${PROJECT_NAME} Qt::Core Qt::Widgets Qt::3DCore Qt::3DExtras
                                      Qt::3DRender Qt::3DInput Qt::SerialPort)
