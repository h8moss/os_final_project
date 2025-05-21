# Basic cmake config
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project
project(my_os VERSION 1.0.0)

# Include
include_directories(
  ./include
)

# Sources
set(SOURCES 
  ./src/main.cc
)

# Executable
add_executable(my_os ${SOURCES})

