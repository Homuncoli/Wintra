#ifndef WINTRA_WINDOW_H
#define WINTRA_WINDOW_H

#include <GLFW/glfw3.h>
#include <string>
#include <algorithm>
#include <functional>

#include "Monitor.h"
#include <Cursor.h>

namespace Wintra {

	class Window {
	public:
		Window(int width, int height, const std::string& title);
		Window(int width, int height, const std::string& title, const Wintra::Monitor& monitor);
		~Window();

		bool isMainWindow() const;
		bool shouldClose() const;
		void setContext() const;
		
		void setTitle(const std::string& title);
		void setCursor(Cursor& cursor);
		void setClose(bool close);

		void setOnResize(const std::function<void(int, int)>& function);
		void setOnClose(std::function<void()> function);

		void update() const;
		
	private:
		void setEvents();

		GLFWwindow* window;
		Cursor cursor;

		std::string title;
		int width, height;

		std::function<void(int, int)> resizeFunction;
		std::function<void()> closeFunction;
		
		static Window* instance;
		friend void framebufferSizeCallback(GLFWwindow* window, int width, int height);
		friend void closeCallback(GLFWwindow* window);
	};
}

#endif