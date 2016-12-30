#pragma once
#include <string>
#include "common_headers.h"
#include <src/Core/Containers/Array.h>
#include <src/Utils/String.h>

using namespace std;
using namespace revo::core::containers;
using namespace revo::utils;

namespace revo {
	namespace graphics {
		class ShaderComponent {
		protected:
			GLuint bufferID;
			std::vector<String> uniformNames;

			void attachToBufferAndCompileShaderSource(const std::string& shaderComponentSource);
			void logFromBuffer();
			void extractUniformNames(const std::string& shaderSourceCode);

		public:
			ShaderComponent();
			ShaderComponent(const ShaderComponent& other);
			~ShaderComponent();

			void initBuffer(uint BUFFER_TYPE);
			void compileFromSource(const std::string& shaderComponentSource);
			void loadShaderSourceFromPath(const std::string& shaderComponentPath);
			const GLuint& getShaderBufferID();
			const std::vector<String>& getUniformNames() const;

			const ShaderComponent& operator=(const ShaderComponent& other);
		};
	}
}