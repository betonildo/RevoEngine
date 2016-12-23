#include "stdafx.h"
#include "ShaderComponent.h"

using namespace std;

namespace revo {
	namespace graphics {
		
		void ShaderComponent::attachToBufferAndCompileShaderSource(const std::string & shaderComponentSource) {
			// Compile Shader Component
			char const * shaderSourcePointer = shaderComponentSource.c_str();
			glShaderSource(this->bufferID, 1, &shaderSourcePointer, NULL);
			glCompileShader(this->bufferID);
			this->logFromBuffer();
		}

		ShaderComponent::ShaderComponent() {
			
		}

		ShaderComponent::~ShaderComponent() {			
			glDeleteShader(this->bufferID);
			std::cout << "Deleted buffer ID" << std::endl;
		}

		void ShaderComponent::initBuffer(uint BUFFER_TYPE) {
			this->bufferID = glCreateShader(BUFFER_TYPE);
		}

		void ShaderComponent::compileFromSource(const std::string& shaderComponentSource) {

			// Instantiate buffer id
			this->attachToBufferAndCompileShaderSource(shaderComponentSource);
		}

		void ShaderComponent::loadShaderSourceFromPath(const std::string& shaderComponentPath) {
			std::string shaderSource = revo::utils::File::readAllText(shaderComponentPath);
			this->compileFromSource(shaderSource);
			std::cout << "Compiling shader: " <<  shaderComponentPath << std::endl;
		}

		const GLuint& ShaderComponent::getShaderBufferID() {
			return this->bufferID;
		}

		void ShaderComponent::logFromBuffer() {
			// Check Shader Component
			GLint Result = GL_FALSE;
			int InfoLogLength;

			glGetShaderiv(this->bufferID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(this->bufferID, GL_INFO_LOG_LENGTH, &InfoLogLength);

			if (InfoLogLength > 0) {
				std::vector<char> shaderComponentErrorMessage(InfoLogLength + 1);
				glGetShaderInfoLog(this->bufferID, InfoLogLength, NULL, &shaderComponentErrorMessage[0]);
				printf("%s\n", &shaderComponentErrorMessage[0]);
			}
		}
	}
}