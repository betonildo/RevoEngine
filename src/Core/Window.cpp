#include "stdafx.h"
#include "Window.h"

namespace revo {

	Window* windowServed;

	void Window::SetService(Window * windowService)
	{
		windowServed = (Window*)windowService;
	}

	Window * Window::BuildService(std::string title, int width, int height)
	{
		if (windowServed != NULL) {
			return windowServed->Create(title, width, height);
		}
		return nullptr;
	}
}