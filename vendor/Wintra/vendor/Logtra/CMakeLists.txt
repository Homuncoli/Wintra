# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Logtra" VERSION 1.0
					DESCRIPTION "A logging library"
					LANGUAGES CXX )


set(LGA_INCLUDE_DIRECTORIES "Logtra/include")

# Include sub-projects.
add_subdirectory ("Logtra")
