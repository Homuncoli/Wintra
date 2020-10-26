#include "..\include\Window.h"

#include "Logtra.h"

namespace Wintra {
	
	void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->width = width;
		win->height = height;

		if (win->resizeFunction)
			win->resizeFunction(width, height);
	}

	void closeCallback(GLFWwindow* window) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (win->closeFunction)
			win->closeFunction();
	}

	Window* Window::instance = nullptr;

	Window::Window(int width, int height, const std::string& title) : width(width), height(height), title(title)
	{
		if (Window::instance == nullptr) {
			window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
			Window::instance = this;
		}
		else {
			window = glfwCreateWindow(width, height, title.c_str(), nullptr, instance->window);
		}
		if (window == nullptr) {
			LGA_ERROR("Window could not be created; Maybe Init() was not called");
		}
		glfwSetWindowUserPointer(window, this);
		setEvents();
	}

	Window::Window(int width, int height, const std::string& title, const Monitor& monitor)
	{
		if (Window::instance == nullptr) {
			window = glfwCreateWindow(width, height, title.c_str(), monitor.monitor, nullptr);
			Window::instance = this;
		}
		else {
			window = glfwCreateWindow(width, height, title.c_str(), monitor.monitor, instance->window);
		}
		glfwSetWindowUserPointer(window, this);
		setEvents();
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
	}

	bool Window::isMainWindow() const
	{
		return Window::instance == this;
	}

	bool Window::shouldClose() const
	{
		return glfwWindowShouldClose(window);
	}

	void Window::setContext() const
	{
		glfwMakeContextCurrent(window);
	}

	void Window::setCursor(Cursor& cursor)
	{
		glfwSetCursor(window, cursor.cursor);
		this->cursor = cursor;
		cursor.cursor = nullptr;
		cursor.image = nullptr;
	}

	void Window::setTitle(const std::string& title)
	{
		this->title = title;
		glfwSetWindowTitle(window, title.c_str());
	}

	void Window::setClose(bool close)
	{
		glfwSetWindowShouldClose(window, close);
	}

	void Window::setOnResize(const std::function<void(int, int)>& function)
	{
		resizeFunction = function;
	}

	void Window::setOnClose(std::function<void()> function)
	{
		closeFunction = function;
	}

	void Window::setEvents()
	{
		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
		glfwSetWindowCloseCallback(window, closeCallback);
	}

	void Window::update() const
	{
		glfwSwapBuffers(window);
	}

}
