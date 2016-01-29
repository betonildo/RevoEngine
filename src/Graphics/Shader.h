#pragma once
#include "definitions.h"

namespace revo {
	namespace graphics {
		class Shader
		{
		private:
			uint mProgram;

		public:
			Shader();
			~Shader();

			void simpleLoad(cstring vertPath, cstring fragPath);
			void simpleUse();
		};
	}
}


