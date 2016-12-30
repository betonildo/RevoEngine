#pragma once

#include <definitions.h>

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