# CMakeList.txt : CMake project for Wintra, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Wintra" VERSION 1.0
                  DESCRIPTION "A Window Library"
                  LANGUAGES CXX)

# Add source to this project's executable.
add_library (Wintra STATIC "include/Wintra.h" "src/Window.cpp" "include/Window.h" "include/Monitor.h" "src/Monitor.cpp" "include/Debug.h" "include/Cursor.h" "src/Cursor.cpp")

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/Logtra)

set(WNA_INCLUDE_DIRECTORIES "Wintra/include" )

target_include_directories(Wintra PUBLIC "include" "vendor/glfw/include" "vendor/Logtra/Logtra/include")
target_link_libraries     (Wintra PUBLIC Logtra glfw ${GLFW_LIBRARIES})

# TODO: Add tests and install targets if needed.
