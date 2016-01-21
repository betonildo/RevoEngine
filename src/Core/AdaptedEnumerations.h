#pragma once

#define SDL2

#ifdef SDL2
	#include <SDL.h>
#endif

namespace revo {
	struct Flags {
#ifdef SDL2
		static enum Window {
			OpenGL = SDL_WINDOW_OPENGL,
			Resizable = SDL_WINDOW_RESIZABLE,
			FullScreen = SDL_WINDOW_FULLSCREEN
		} Window;
#endif
	};
}