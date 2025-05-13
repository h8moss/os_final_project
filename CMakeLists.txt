# Basic cmake config
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project
project(my_os VERSION 1.0.0)

# Include
include_directories(
  ${CMAKE_SOURCE_DIR}/include
)

# System include, if needed
include_directories(SYSTEM
  ${CMAKE_SOURCE_DIR}/sys_include
)

# Debug flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")

# Sources
set(SOURCES ${CMAKE_SOURCE_DIR}/src/main.cc)

# Executable
add_executable(my_os ${SOURCES})

