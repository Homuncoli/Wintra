# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Wintra" VERSION 1.0
                  DESCRIPTION "A Window Library"
                  LANGUAGES CXX)

# Include sub-projects.
add_subdirectory("vendor")

add_subdirectory("src")