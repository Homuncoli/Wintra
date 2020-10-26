#ifndef WINTRA_WINDOW_H
#define WINTRA_WINDOW_H

#include <GLFW/glfw3.h>
#include <string>
#include <algorithm>
#include <map>
#include <functional>

#include "Monitor.h"
#include <Cursor.h>
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
		int getWidth() const;
		int getHeight() const;
		float getAspectRatio() const;
		
		void setTitle(const std::string& title);
		void setCursor(Cursor& cursor);
		void setClose(bool close);
		void setCursorMode(const Cursor::Cursor_Mode& mode);

		void setOnResize(const std::function<void(int, int)>& function);
		void setOnClose(std::function<void()> function);
		void setOnKeyPress(int key, std::function<void()> function);
		void setOnKeyRelease(int key, std::function<void()> function);
		void setOnKeyHold(int key, std::function<void()> function);
		void setScrollCallback(std::function<void(double, double)> function);
		void setCursorPosCallback(std::function<void(double, double)> function);
		void setMouseButtonPress(int key, std::function<void()> function);
		void setMouseButtonRelease(int key, std::function<void()> function);
		void setMouseButtonHold(int key, std::function<void()> function);

		void update() const;
		
	private:
		void setEvents();

		GLFWwindow* window;
		Cursor cursor;

		std::string title;
		int width, height;

		std::function<void(int, int)> resizeFunction;
		std::function<void()> closeFunction;
		std::map<int, std::map<int, std::function<void()>>> keyMap;
		std::function<void(double, double)> scrollFunction;
		std::function<void(double, double)> cursorPosFunction;
		std::map<int, std::map<int, std::function<void()>>> mouseMap;
		
		static Window* instance;
		friend void framebufferSizeCallback(GLFWwindow* window, int width, int height);
		friend void closeCallback(GLFWwindow* window);
		friend void keyCallback(GLFWwindow*, int, int, int, int);
		friend void scrollCallback(GLFWwindow*, double, double);
		friend void cursorPosCallback(GLFWwindow*, double, double);
		friend void mouseButtonCallback(GLFWwindow* window, int, int, int);
	};
}

#endif