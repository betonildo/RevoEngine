#pragma once
#include "common_headers.h"

namespace revo {
	namespace graphics {
		class Shader
		{
		private:
			uint mProgram;

		public:
			Shader();
			~Shader();

			void simpleLoad(const char* vertPath, const char* fragPath);
			void simpleUse();
		};
	}
}


