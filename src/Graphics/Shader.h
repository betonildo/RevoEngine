#pragma once
#include "common_headers.h"
#include <src\Maths\Matrix4.h>

using namespace revo::maths;

namespace revo {
	namespace graphics {

		

		class Shader
		{
		private:
			uint mProgram;

		public:
			Shader();
			~Shader();

			void load(const char* vertPath, const char* fragPath);
			void bind();
			void unbind();

			void setMatrix4(const char* uniformKey, const Matrix4& m);
		};
	}
}


