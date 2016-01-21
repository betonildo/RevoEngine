#pragma once
#include <SDL.h>
#include <src/Core/Window.h>

namespace revo {

	namespace adapter {

		class WindowSDL2 : public Window
		{
		public:
			SDL_Window* mWindow;
			SDL_Event mEvent;

			std::string mTitle;
			int mWidth, mHeight;
			bool mClosed;

		public:
			WindowSDL2();
			~WindowSDL2();

			// Inherited via Window
			virtual void update() override;
			virtual bool closed() override;
			virtual Window * create(std::string title, int width, int height, int flags = 0) override;
			
		};
	}
}

