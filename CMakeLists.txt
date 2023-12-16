# Defining CMake version
cmake_minimum_required(VERSION 3.10)

# Setting up C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Defining project name
project(exploringcpp)

# Add executable
add_executable(main main.cpp)

# Specifying include directories
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}")

# Configuration file
configure_file(config.h.in "${PROJECT_BINARY_DIR}/include/config.h")

# Adding libraries
add_library(module ./src/module.cpp)
add_library(ui ./src/ui.cpp)
add_library(command_cli ./src/command_cli.cpp)
add_library(utils ./src/utils.cpp)

# Specifying include directories
target_include_directories(module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include") 
target_include_directories(ui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")     
target_include_directories(command_cli PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")  
target_include_directories(utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Linking libraries
target_link_libraries(main PUBLIC module ui command_cli utils)

# Include directories
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}/include")