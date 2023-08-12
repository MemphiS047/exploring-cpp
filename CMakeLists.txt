# Defining CMake version
cmake_minimum_required(VERSION 3.10)

# Setting up C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Defining project name
project(exploringcpp)

# Add executable
add_executable(main main.cpp)

# Specfiying include directories
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}")

# Configuration file
configure_file(config.h.in "${PROJECT_BINARY_DIR}/include/config.h")

# Adding libraries
add_library(module ./src/module.cpp)
add_library(ui ./src/ui.cpp)
add_library(command_cli ./src/command_cli.cpp)

# Adding subdirectories
# add_subdirectory(src)
# add_subdirectory(include)
# add_subdirectory(lib)

# Linking libraries
target_link_libraries(main PUBLIC module ui command_cli)

# Include directories
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}/include")