#include "stdafx.h"
#include "CoreServiceSDL2.h"

namespace revo {
	namespace adapter {

		CoreServiceSDL2::CoreServiceSDL2()
		{
		}


		CoreServiceSDL2::~CoreServiceSDL2()
		{
		}

		void CoreServiceSDL2::initialize()
		{
			if (SDL_Init(SDL_INIT_VIDEO) != 0) { 
				std::cerr << "SDL2 is not initialized!" << std::endl;
			}
		}

		void CoreServiceSDL2::terminate()
		{
			SDL_Quit();
		}
	}
}
