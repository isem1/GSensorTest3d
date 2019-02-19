
#Set minimal CMake version to 3.8.2
cmake_minimum_required( VERSION 3.8.2 FATAL_ERROR )

#Set project name , version and using language
project( 3Dcube VERSION 0.1.0 LANGUAGES CXX )

#Find includes in corresponding build directories
set( CMAKE_INCLUDE_CURRENT_DIR ON )

###################### QT SETTINGS ###########################

#Enable automatic invocation of MOC & UIC
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

# Set some Win32 Specific Settings
if( WIN32 )
    set( GUI_TYPE WIN32 )
endif()

# Set some Apple MacOS Specific settings
if( APPLE )
    set( GUI_TYPE MACOSX_BUNDLE )
endif()

#Enable support of C++17
if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17" )
else()
    set( CMAKE_CXX_STANDARD 17 )
endif()

#Set Qt directories for resolve Qt3DExtras trouble
#Change this paths to other when you need to compile project with another compiler

#Find all needed packages for build application
find_package( Qt5 REQUIRED COMPONENTS 	Core
                                        Widgets
                                        3DCore
                                        3DInput
                                        3DExtras
                                        3DRender
                                        SerialPort )

###################### QT SETTINGS ###########################

###################### PROJECT SETTINGS ######################

#Set output directories for generated files
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

#Set directories with sources and headers
set( SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( HEADER_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/inc )

message( "Current source directory is:" ${SOURCE_DIR} )

set( SOURCES 	${SOURCE_DIR}/main.cpp
                ${SOURCE_DIR}/scenemodifier.cpp
                ${SOURCE_DIR}/inputdialog.cpp
                ${SOURCE_DIR}/serialport.cpp
                ${SOURCE_DIR}/mainwindow.cpp )

set( HEADER_FILES 	${HEADER_DIR}/scenemodifier.hpp
                        ${HEADER_DIR}/inputdialog.hpp
                        ${HEADER_DIR}/serialport.hpp
                        ${HEADER_DIR}/parameters.hpp
                        ${HEADER_DIR}/mainwindow.hpp )

message( "Added source files:" ${SOURCES} )


add_executable( ${PROJECT_NAME} ${GUI_TYPE} ${SOURCES} ${HEADER_FILES} )

#Set up target include directories
target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc )

#Set up target link libraries
target_link_libraries( ${PROJECT_NAME} 	Qt5::Core
                                        Qt5::Widgets
                                        Qt5::3DCore
                                        Qt5::3DExtras
                                        Qt5::3DRender
                                        Qt5::3DInput
                                        Qt5::SerialPort )

###################### PROJECT SETTINGS ######################
