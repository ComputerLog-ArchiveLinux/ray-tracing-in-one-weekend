# CMake project
cmake_minimum_required(VERSION 4.2)
project(ray-tracing-in-one-weekend)

# Main executable
add_executable(main "src/main.cpp")

# Include directories
target_include_directories(main PRIVATE "src/")