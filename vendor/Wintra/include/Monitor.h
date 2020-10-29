#ifndef WINTRA_MONITOR_H
#define WINTRA_MONITOR_H

#include <glfw/glfw3.h>

#include <vector>
#include <string>

namespace Wintra {


	class Window;

	class Monitor {
	public:
		static std::vector<Monitor> GetMonitors();
		static Monitor getPrimaryMonitor();

		Monitor();
		Monitor(GLFWmonitor* monitor);

		std::string getName() const;
		int* getPos() const;

	private:
		GLFWmonitor* monitor;

		friend class Window;
	};

}

#endif // !WINTRA_MONITOR_H
