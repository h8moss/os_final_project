# Basic cmake config
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project
project(my_os VERSION 1.0.0)

# Include
include_directories(
  ./include
)

# Sources
set(SOURCES 
  ./src/modules/file_system/file_system_module.cc
  ./src/modules/file_system/fs_directory.cc
  ./src/modules/file_system/fs_file.cc
  ./src/modules/file_system/fs_node.cc
  ./src/modules/usuarios/usuarios.cpp
  ./src/main.cc
  ./src/program.cc
)

# Users file
file(COPY ./usuarios.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Executable
add_executable(my_os ${SOURCES})
