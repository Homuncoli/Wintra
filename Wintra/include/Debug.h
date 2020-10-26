#ifndef WINTRA_DEBUG_H
#define WINTRA_DEBUG_H

namespace Wintra {
	namespace Debug {
		void glfwErrorCallback(int error, const char* message) {
			LGA_ERROR(std::to_string(error) + " - " + std::string(message));
		}
	}
}

#endif