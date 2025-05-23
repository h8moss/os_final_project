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
  ./src/common/modules/fs_module.cc
  ./src/common/util/file_tree/file_tree_directory.cc
  ./src/common/util/file_tree/file_tree_file.cc
  ./src/common/util/file_tree/file_tree_node.cc
  ./src/common/util/file_tree/file_tree.cc
  ./src/common/util/path/get_path_segments.cc
  ./src/common/util/user_exception.cc
  ./src/common/program.cc
  ./src/main.cc
)

# Executable
add_executable(my_os ${SOURCES})

