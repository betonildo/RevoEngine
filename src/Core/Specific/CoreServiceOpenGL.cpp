#include "stdafx.h"
#include "CoreServiceOpenGL.h"


namespace revo {
	namespace adapter {
		CoreServiceOpenGL::CoreServiceOpenGL()
		{
			this->mHasInit = false;
		}


		CoreServiceOpenGL::~CoreServiceOpenGL()
		{
		}

		void CoreServiceOpenGL::initialize()
		{
			
			// Set our OpenGL version.
			// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

			// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

			// Turn on double buffering with a 24bit Z buffer.
			// You may need to change this to 16 or 32 for your system
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

			this->mHasInit = true;
		}

		void CoreServiceOpenGL::setFlag(int * flagsArray, size_t flagsArraySize)
		{
		}

		void CoreServiceOpenGL::terminate()
		{
		}

		bool CoreServiceOpenGL::hasInitialized()
		{
			return this->mHasInit;
		}
		
	}
}