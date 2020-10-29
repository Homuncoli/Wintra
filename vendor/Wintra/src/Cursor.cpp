#include "Cursor.h"
#include <Logtra.h>

namespace Wintra {
	Cursor::Cursor() : cursor(nullptr)
	{
		
	}

	Cursor::Cursor(const Cursor_Shape& shape)
	{
		cursor = glfwCreateStandardCursor((int)shape);
	}

	Cursor::Cursor(int width, int height, unsigned char* data, int xhot, int yhot)
	{
		image = new GLFWimage();
		image->height = height;  image->width = width;
		image->pixels = data;
		cursor = glfwCreateCursor(image, xhot, yhot);
	}

	Cursor::~Cursor() {
		glfwDestroyCursor(cursor);
		delete image;
	}
}