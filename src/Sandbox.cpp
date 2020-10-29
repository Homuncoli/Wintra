#include "Wintra.h"

int main() {
	{
		Logtra::Logger logger("Sandbox");
		LGA_USE_LOGGER(logger);

		Wintra::Init();

		Wintra::Window window(800, 600, "Window");
		window.setContext();

		window.setOnKeyPress((int)'A', [&]() { std::cout << "A Pressed" << '\n'; });

		while (!window.shouldClose()) {
			Wintra::Window::PollEvents();

			window.render();
		}
	}
	Wintra::Terminate();

	return 0;
}