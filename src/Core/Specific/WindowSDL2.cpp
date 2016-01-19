#include "stdafx.h"
#include "WindowSDL2.h"

namespace revo {

	namespace adapter {

		WindowSDL2::WindowSDL2()
		{
			this->mWindow = NULL;
			this->mClosed = false;
		}


		WindowSDL2::~WindowSDL2()
		{
			SDL_DestroyWindow(this->mWindow);
		}

		void WindowSDL2::update()
		{
			while (SDL_PollEvent(&this->mEvent)) {
				switch (this->mEvent.type) {
				case SDL_QUIT:
					this->mClosed = true;
					break;
				}
			}
		}

		bool WindowSDL2::closed()
		{
			return this->mClosed;
		}

		Window * WindowSDL2::create(std::string title, int width, int height)
		{
			///store values
			this->mTitle = title;
			this->mWidth = width;
			this->mHeight = height;

			// creates sdl2 window
			this->mWindow = SDL_CreateWindow(this->mTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

			return this;
		}
	}
}
