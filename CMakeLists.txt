# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)



project ("Wintra" VERSION 1.0
                  DESCRIPTION "A Window Library"
                  LANGUAGES CXX)

# Include sub-projects.
add_subdirectory ("Wintra")
add_subdirectory ("vendor/Logtra")

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "vendor/Logtra/Logtra/include")