#pragma once
#include "stdafx.h"
#include "Window.h"

namespace revo {
	class WindowSDL2 : public Window
	{
		SDL_Window* mWindow;
		SDL_GLContext mContext;


		std::string title;
		int width, height;
		bool closed;

	public:
		WindowSDL2();
		~WindowSDL2();

		// Inherited via Window
		virtual void Update() override;

		virtual bool Closed() override;

		virtual Window * Create(std::string title, int width, int height) override;

	};
}


