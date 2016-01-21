#include "stdafx.h"
#include "CoreServiceSDL2.h"

namespace revo {
	namespace adapter {

		CoreServiceSDL2::CoreServiceSDL2()
		{
			this->mHasInit = false;
		}


		CoreServiceSDL2::~CoreServiceSDL2()
		{
		}

		void CoreServiceSDL2::initialize()
		{
			if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
				std::cerr << "SDL2 is not initialized!" << std::endl;
			}
			
			this->mHasInit = true;
		}

		void CoreServiceSDL2::setFlag(int * flagsArray, size_t flagsArraySize)
		{
		}

		void CoreServiceSDL2::terminate()
		{
			SDL_Quit();
		}

		bool CoreServiceSDL2::hasInitialized()
		{
			return this->mHasInit;
		}

	}
}
