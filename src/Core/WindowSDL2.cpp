#include "stdafx.h"
#include "WindowSDL2.h"

namespace revo {
	WindowSDL2::WindowSDL2()
	{
		this->closed = false;
	}

	WindowSDL2::~WindowSDL2()
	{
		SDL_Quit();
	}

	void WindowSDL2::Update()
	{
		SDL_Event event;
		while (!closed) {
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					closed = true;
					break;
				}
			}

			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			SDL_GL_SwapWindow(this->mWindow);
		}
	}

	bool WindowSDL2::Closed()
	{
		return this->closed;
	}

	Window * WindowSDL2::Create(std::string title, int width, int height)
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "Not Initialized!" << std::endl;
		}

		glewExperimental = true;
		if (!glewInit()) {
			std::cout << "Glew Not initialized!" << std::endl;
		}

		// store info 
		this->width = width;
		this->height = height;
		this->title = title;

		//Creates window context
		this->mWindow = SDL_CreateWindow( title.c_str(), 256, 256, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

		// Create an OpenGL context associated with the window.
		this->mContext = SDL_GL_CreateContext(this->mWindow);

		this->closed = false;
		
		//return this window
		return this;
	}
}
