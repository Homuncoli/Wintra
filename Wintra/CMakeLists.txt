# CMakeList.txt : CMake project for Wintra, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Wintra "src/Wintra.cpp" "include/Wintra.h" "src/Window.cpp" "include/Window.h" "include/Monitor.h" "src/Monitor.cpp" "include/Debug.h" "include/Cursor.h" "src/Cursor.cpp")

set(WNA_INCLUDE_DIRECTORIES "Wintra/include" )

target_include_directories(Wintra PUBLIC "include")
target_link_libraries     (Wintra PUBLIC Logtra glfw ${GLFW_LIBRARIES})

# TODO: Add tests and install targets if needed.
