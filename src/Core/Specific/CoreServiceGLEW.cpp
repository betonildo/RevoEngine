#include "stdafx.h"
#include "CoreServiceGLEW.h"

namespace revo {
	namespace adapter {

		CoreServiceGLEW::CoreServiceGLEW()
		{
		}


		CoreServiceGLEW::~CoreServiceGLEW()
		{
		}

		void CoreServiceGLEW::initialize()
		{
			glewExperimental = GL_TRUE;
			if (!glewInit()) {
				std::cerr << "Glew not initialized" << std::endl;
			}
		}

		void CoreServiceGLEW::terminate()
		{
		}
	}
}


