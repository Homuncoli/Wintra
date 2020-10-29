# CMakeList.txt : CMake project for Wintra, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (Sandbox VERSION 1.0
	DESCRIPTION "A Sandbox for Wintra"
	LANGUAGES CXX)

add_subdirectory(vendor/Wintra/)

# Add source to this project's executable.
add_executable (Sandbox "src/Sandbox.cpp")

target_include_directories(Sandbox PUBLIC "vendor/Wintra/include")
target_link_libraries     (Sandbox PUBLIC Wintra)

# TODO: Add tests and install targets if needed.
