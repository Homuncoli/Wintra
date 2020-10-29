# CMakeList.txt : CMake project for Logtra, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (Logtra STATIC  "include/Logtra.h" "include/Logger.h" "src/Logger.cpp")
target_include_directories (Logtra PUBLIC ../${LGA_INCLUDE_DIRECTORIES})

# TODO: Add tests and install targets if needed.
