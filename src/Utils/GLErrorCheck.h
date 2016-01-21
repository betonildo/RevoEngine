#pragma once

namespace revo {
	namespace utils {

		class GLErrorCheck
		{
		public:
			static void openglErrorCheck(const char* file, int line);
		};
	}
}

#define check_gl_error() revo::utils::GLErrorCheck::openglErrorCheck(__FILE__,__LINE__)