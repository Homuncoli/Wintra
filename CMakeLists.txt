# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory ("vendor/Logtra")
add_subdirectory ("vendor/glfw")

project ("Wintra" VERSION 1.0
                  DESCRIPTION "A Window Library"
                  LANGUAGES CXX)

# Include sub-projects.
add_subdirectory ("Wintra")

target_include_directories(Wintra PUBLIC "vendor/Logtra/Logtra/include")
target_include_directories(Wintra PUBLIC "vendor/glfw/include")
target_include_directories(Wintra PUBLIC "vendor/Logtra/"${LGA_INCLUDE_DIRECTORIES})