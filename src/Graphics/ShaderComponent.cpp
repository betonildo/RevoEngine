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

		ShaderComponent::ShaderComponent(const ShaderComponent & other) {

			(*this) = other;
		}

		ShaderComponent::~ShaderComponent() {			
			glDeleteShader(this->bufferID);
			DPRINTLN("Deleted buffer ID");
		}

		void ShaderComponent::initBuffer(uint BUFFER_TYPE) {
			this->bufferID = glCreateShader(BUFFER_TYPE);
		}

		void ShaderComponent::compileFromSource(const std::string& shaderComponentSource) {

			// Instantiate buffer id
			this->attachToBufferAndCompileShaderSource(shaderComponentSource);
			this->extractUniformNames(shaderComponentSource);
		}

		void ShaderComponent::loadShaderSourceFromPath(const std::string& shaderComponentPath) {
			std::string shaderSource = revo::utils::File::readAllText(shaderComponentPath);
			this->compileFromSource(shaderSource);
			DPRINTLN("Compiling shader: " + shaderComponentPath);
		}

		const GLuint& ShaderComponent::getShaderBufferID() {
			return this->bufferID;
		}

		const std::vector<String>& ShaderComponent::getUniformNames() const {
			return this->uniformNames;
		}

		const ShaderComponent & ShaderComponent::operator=(const ShaderComponent & other) {

			bufferID = other.bufferID;
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
				DPRINTLN(&shaderComponentErrorMessage[0]);
			}
		}
		void ShaderComponent::extractUniformNames(const std::string & shaderSourceCode) {
			
			using namespace revo::utils;
			const char* UNIFORM = "uniform";
			std::vector<wchar_t> delimitators;
			delimitators.push_back(' ');
			delimitators.push_back(';');
			delimitators.push_back('=');
			delimitators.push_back('\n');

			std::vector<String> lines = String(shaderSourceCode).split('\n');

			for (uint i = 0; i < lines.size(); i++) {
				
				String line = lines[i];
				// has uniform
				if (line.contains(UNIFORM)) {
					
					// get uniform name and append it to uniforms names
					std::vector<String> lineComponents = line.split(' ');
					String uniformName = lineComponents[2].copyUntilFind(delimitators);
					this->uniformNames.push_back(uniformName);
				}
			}
		}
	}
}