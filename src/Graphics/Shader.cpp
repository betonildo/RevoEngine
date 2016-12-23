#include "stdafx.h"
#include "Shader.h"

using namespace std;

namespace revo {
	namespace graphics {

		Shader::Shader() {
			this->mProgram = glCreateProgram();
		}

		Shader::~Shader() {
			glDeleteShader(this->mProgram);
		}

		void Shader::attachComponent(uint BUFFER_TYPE, const string& shaderPath) {
			// Link the program			
			switch (BUFFER_TYPE) {
			case GL_FRAGMENT_SHADER:
				this->fragment.initBuffer(GL_FRAGMENT_SHADER);
				this->fragment.loadShaderSourceFromPath(shaderPath);
				glAttachShader(this->mProgram, this->fragment.getShaderBufferID());
				break;

			case GL_VERTEX_SHADER:
				this->vertex.initBuffer(GL_VERTEX_SHADER);
				this->vertex.loadShaderSourceFromPath(shaderPath);
				glAttachShader(this->mProgram, this->vertex.getShaderBufferID());
				break;

			default:
				printf("No Compatible Shader Provided\n");
				break;
			}
		}

		void Shader::linkAll() {
			glLinkProgram(this->mProgram);
			this->logProgramErrors();
		}

		void Shader::logProgramErrors() {
			// Check the program
			GLint Result = GL_FALSE;
			int InfoLogLength;

			glGetProgramiv(this->mProgram, GL_LINK_STATUS, &Result);
			glGetProgramiv(this->mProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
			
			if (InfoLogLength > 0) {
				std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
				glGetProgramInfoLog(this->mProgram, InfoLogLength, NULL, &ProgramErrorMessage[0]);
				printf("%s\n", &ProgramErrorMessage[0]);
			}
		}

		void Shader::bind() {
			glUseProgram(this->mProgram);
		}

		void Shader::unbind() {
			glUseProgram(0);
		}
	}
}

