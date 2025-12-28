# CMake project
cmake_minimum_required(VERSION 4.2)
project(ray-tracing-in-one-weekend)

# Source files
set( SRC_FILES
    "src/stb_impl.cpp"
    "src/main.cpp"
)

# Main executable
add_executable(main ${SRC_FILES})

# Include directories
target_include_directories(main PRIVATE "src/")
target_include_directories(main PRIVATE "lib/stb/")