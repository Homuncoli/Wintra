// Wintra.h : Include file for standard system include files,
// or project specific include files.

#ifndef WINTRA_WINTRA_H
#define WINTRA_WINTRA_H

#include <iostream>

#include "Logtra.h"
#include "Debug.h"

#include "Window.h"
#include "Monitor.h"

namespace Wintra {
	void Init() {
		if (!glfwInit()) {
			LGA_CRITICAL("GLFW could not be initialized");
		}
		else {
			LGA_SUCCESS("GLFW was initialized");
		}
		glfwSetErrorCallback(Wintra::Debug::glfwErrorCallback);
	}

	void* getProcAddress() {
		return glfwGetProcAddress;
	}

	void setOpenGLVersion(int major, int minor) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	}

	void Terminate() {
		glfwTerminate();
		LGA_LOG("Terminated");
	}
}

#endif // !WINTRA_WINTRA_H