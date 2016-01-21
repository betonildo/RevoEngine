#include "stdafx.h"
#include "CoreServiceGLEW.h"

namespace revo {
	namespace adapter {

		CoreServiceGLEW::CoreServiceGLEW()
		{
			this->mHasInit = false;
		}


		CoreServiceGLEW::~CoreServiceGLEW()
		{
		}

		void CoreServiceGLEW::initialize()
		{
			
			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK) {
				std::cerr << "Glew not initialized" << std::endl;
			}
			
			this->mHasInit = true;
		}

		void CoreServiceGLEW::setFlag(int * flagsArray, size_t flagsArraySize)
		{
		}

		void CoreServiceGLEW::terminate()
		{
		}

		bool CoreServiceGLEW::hasInitialized()
		{
			return this->mHasInit;
		}

	}
}


