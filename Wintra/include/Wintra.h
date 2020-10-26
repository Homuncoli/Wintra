// Wintra.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

#include "Logtra.h"
#include "Debug.h"

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

// TODO: Reference additional headers your program requires here.
#include "Window.h"
#include "Monitor.h"