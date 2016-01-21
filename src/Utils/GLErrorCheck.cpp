#include <GL\glew.h>
#include "stdafx.h"
#include "GLErrorCheck.h"

using namespace std;


namespace revo {
	namespace utils {

		void GLErrorCheck::openglErrorCheck(const char* file, int line)
		{
			GLenum err(glGetError());

			while (err != GL_NO_ERROR) {
				string error;

				switch (err) {
				case GL_INVALID_OPERATION:      error = "INVALID_OPERATION";      break;
				case GL_INVALID_ENUM:           error = "INVALID_ENUM";           break;
				case GL_INVALID_VALUE:          error = "INVALID_VALUE";          break;
				case GL_OUT_OF_MEMORY:          error = "OUT_OF_MEMORY";          break;
				case GL_INVALID_FRAMEBUFFER_OPERATION:  error = "INVALID_FRAMEBUFFER_OPERATION";  break;
				}

				cerr << "OpenGL Error: GL_" << error.c_str() << " - " << file << ":" << line << endl;
				err = glGetError();
			}
		}
	}
}