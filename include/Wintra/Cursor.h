#ifndef WINTRA_CURSOR_H
#define WINTRA_CURSOR_H

#include <GLFW/glfw3.h>

namespace Wintra {

	class Window;

	class Cursor {
	public:
		enum class Cursor_Shape {
			Arrow = GLFW_ARROW_CURSOR,
			IBeam = GLFW_IBEAM_CURSOR,
			Crosshair = GLFW_CROSSHAIR_CURSOR,
			Hand = GLFW_HAND_CURSOR,
			HResize = GLFW_HRESIZE_CURSOR,
			VResize = GLFW_VRESIZE_CURSOR
		};

		enum class Cursor_Mode {
			Normal = GLFW_CURSOR_NORMAL,
			Hidden = GLFW_CURSOR_HIDDEN,
			Disabled = GLFW_CURSOR_DISABLED
		};

		Cursor();
		Cursor(int width, int height, unsigned char* data, int xhot, int yhot);
		Cursor(const Cursor_Shape& shape);
		~Cursor();

	private:
		GLFWcursor* cursor;
		GLFWimage* image{ nullptr };

		friend class Window;
	};
}

#endif