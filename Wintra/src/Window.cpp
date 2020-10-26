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

	void keyCallback(GLFWwindow* window, int key, int scan, int action, int mode) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (win->keyMap.find(key) != win->keyMap.end())
			if (win->keyMap[key].find(action) != win->keyMap[key].end())
				win->keyMap[key][action]();
	}

	void scrollCallback(GLFWwindow* window, double x, double y) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (win->scrollFunction)
			win->scrollFunction(x,y);
	}

	void cursorPosCallback(GLFWwindow* window, double x, double y) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (win->cursorPosFunction)
			win->cursorPosFunction(x, y);
	}

	void mouseButtonCallback(GLFWwindow* window, int key, int action, int mode) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (win->mouseMap.find(key) != win->mouseMap.end())
			if (win->mouseMap[key].find(action) != win->mouseMap[key].end())
				win->mouseMap[key][action]();
	}

	void refreshCallback(GLFWwindow* window) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (win->refreshFunction)
			win->refreshFunction();
	}

	void focusCallback(GLFWwindow* window, int focus) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (win->focusFunction)
			win->focusFunction(focus);
	}

	void posCallback(GLFWwindow* window, int x, int y) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (win->posFunction)
			win->posFunction(x,y);
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
		if (!window) {
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

	int Window::getWidth() const
	{
		return width;
	}

	int Window::getHeight() const
	{
		return height;
	}

	float Window::getAspectRatio() const
	{
		return (float)width/height;
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

	void Window::setCursorMode(const Cursor::Cursor_Mode& mode)
	{
		glfwSetInputMode(window, GLFW_CURSOR, (int)mode);
	}

	void Window::enableVsync(bool enable)
	{
		glfwSwapInterval(enable);
	}

	void Window::setOnResize(const std::function<void(int, int)>& function)
	{
		resizeFunction = function;
	}

	void Window::setOnClose(std::function<void()> function)
	{
		closeFunction = function;
	}

	void Window::setOnKeyPress(int key, std::function<void()> function)
	{
		if (keyMap.find(key) == keyMap.end()) {
			keyMap.emplace(key, std::map<int, std::function<void()>>());
		}
		if (keyMap[key].find(GLFW_PRESS) != keyMap[key].end()) {
			keyMap[key][GLFW_PRESS] = function;
		}
		else {
			keyMap[key].emplace(GLFW_PRESS, function);
		}
	}

	void Window::setOnKeyRelease(int key, std::function<void()> function)
	{
		if (keyMap.find(key) == keyMap.end()) {
			keyMap.emplace(key, std::map<int, std::function<void()>>());
		}
		if (keyMap[key].find(GLFW_RELEASE) != keyMap[key].end()) {
			keyMap[key][GLFW_RELEASE] = function;
		}
		else {
			keyMap[key].emplace(GLFW_RELEASE, function);
		}
	}

	void Window::setOnKeyHold(int key, std::function<void()> function)
	{
		if (keyMap.find(key) == keyMap.end()) {
			keyMap.emplace(key, std::map<int, std::function<void()>>());
		}
		if (keyMap[key].find(GLFW_REPEAT) != keyMap[key].end()) {
			keyMap[key][GLFW_REPEAT] = function;
		}
		else {
			keyMap[key].emplace(GLFW_REPEAT, function);
		}
	}

	void Window::setScrollCallback(std::function<void(double, double)> function)
	{
		scrollFunction = function;
	}

	void Window::setCursorPosCallback(std::function<void(double, double)> function)
	{
		cursorPosFunction = function;
	}

	void Window::setMouseButtonPress(int key, std::function<void()> function)
	{
		if (mouseMap.find(key) == mouseMap.end()) {
			mouseMap.emplace(key, std::map<int, std::function<void()>>());
		}
		if (mouseMap[key].find(GLFW_PRESS) != mouseMap[key].end()) {
			mouseMap[key][GLFW_PRESS] = function;
		}
		else {
			mouseMap[key].emplace(GLFW_PRESS, function);
		}
	}

	void Window::setMouseButtonRelease(int key, std::function<void()> function)
	{
		if (mouseMap.find(key) == mouseMap.end()) {
			mouseMap.emplace(key, std::map<int, std::function<void()>>());
		}
		if (mouseMap[key].find(GLFW_RELEASE) != mouseMap[key].end()) {
			mouseMap[key][GLFW_RELEASE] = function;
		}
		else {
			mouseMap[key].emplace(GLFW_RELEASE, function);
		}
	}

	void Window::setMouseButtonHold(int key, std::function<void()> function)
	{
		if (mouseMap.find(key) == mouseMap.end()) {
			mouseMap.emplace(key, std::map<int, std::function<void()>>());
		}
		if (mouseMap[key].find(GLFW_REPEAT) != mouseMap[key].end()) {
			mouseMap[key][GLFW_REPEAT] = function;
		}
		else {
			mouseMap[key].emplace(GLFW_REPEAT, function);
		}
	}

	void Window::setRefreshCallback(std::function<void()> function)
	{
		refreshFunction = function;
	}

	void Window::setFocusCallback(std::function<void(int)> function)
	{
		focusFunction = function;
	}

	void Window::setPosCallback(std::function<void(int, int)> function)
	{
		posFunction = function;
	}

	void Window::setEvents()
	{
		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
		glfwSetWindowCloseCallback(window, closeCallback);
		glfwSetKeyCallback(window, keyCallback);
		glfwSetScrollCallback(window, scrollCallback);
		glfwSetCursorPosCallback(window, cursorPosCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwSetWindowRefreshCallback(window, refreshCallback);
		glfwSetWindowFocusCallback(window, focusCallback);
		glfwSetWindowPosCallback(window, posCallback);
	}

	void Window::update() const
	{
		glfwSwapBuffers(window);
	}

}
