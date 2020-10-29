# CMakeList.txt : CMake project for Wintra, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (Wintra STATIC  "Window.cpp" "Monitor.cpp" "Cursor.cpp")

target_include_directories(Wintra PUBLIC "../include")
target_link_libraries     (Wintra PUBLIC Logtra glfw ${GLFW_LIBRARIES})

# TODO: Add tests and install targets if needed.
