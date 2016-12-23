#pragma once
#include <string>
#include "common_headers.h"
using namespace std;

namespace revo {
	namespace graphics {
		class ShaderComponent {
		protected:
			GLuint bufferID;
			void attachToBufferAndCompileShaderSource(const std::string& shaderComponentSource);
			void logFromBuffer();			

		public:
			ShaderComponent();
			~ShaderComponent();


			void initBuffer(uint BUFFER_TYPE);
			void compileFromSource(const std::string& shaderComponentSource);
			void loadShaderSourceFromPath(const std::string& shaderComponentPath);
			const GLuint& getShaderBufferID();
		};
	}
}