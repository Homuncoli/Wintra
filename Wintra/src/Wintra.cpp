// Wintra.cpp : Defines the entry point for the application.
//

#include <GLFW/glfw3.h>

#include "Wintra.h"
#include "Window.h"

#include "Logtra.h"
#include "Debug.h"
#include <Monitor.h>

using namespace std;

int main()
{
	{
		Logtra::Logger logger("Wintra");
		LGA_USE_LOGGER(logger);

		Wintra::Init();
		Wintra::setOpenGLVersion(3, 3);

		Wintra::Window title(800, 600, "Title");
		title.setContext();
		Wintra::Cursor cursor(Wintra::Cursor::Cursor_Shape::Crosshair);
		title.setCursor(cursor);

		while (!title.shouldClose()) {
			glfwPollEvents();

			title.setContext();
			title.update();
		}
	}
	Wintra::Terminate();
	return 0;
}
