# CMakeList.txt : CMake project for Wintra, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Wintra "Wintra.cpp" "Wintra.h")

target_include_directories (Wintra PUBLIC "../vendor/Logtra/Logtra/include" "../vendor/Logtra/Logtra/src")
target_link_libraries    (Wintra PUBLIC Logtra)

# TODO: Add tests and install targets if needed.
