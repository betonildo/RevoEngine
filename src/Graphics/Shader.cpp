#include "stdafx.h"
#include "Shader.h"

using namespace std;
using namespace revo::maths;

namespace revo {
	namespace graphics {

		Shader::Shader() {
			this->mProgram = glCreateProgram();
		}

		Shader::Shader(const Shader & other) {
			(*this) = other;
		}

		Shader::~Shader() {
			glDeleteShader(this->mProgram);
		}

		void Shader::attachComponent(uint BUFFER_TYPE, const string& shaderPath) {
			// Link the program			
			switch (BUFFER_TYPE) {
			case GL_FRAGMENT_SHADER:
				fragment.initBuffer(GL_FRAGMENT_SHADER);
				fragment.loadShaderSourceFromPath(shaderPath);
				appendUniforms(fragment.getUniformNames());
				glAttachShader(this->mProgram, this->fragment.getShaderBufferID());
				break;

			case GL_VERTEX_SHADER:
				vertex.initBuffer(GL_VERTEX_SHADER);
				vertex.loadShaderSourceFromPath(shaderPath);
				appendUniforms(vertex.getUniformNames());
				glAttachShader(this->mProgram, this->vertex.getShaderBufferID());
				break;

			case GL_GEOMETRY_SHADER:
			default:
				DPRINTLN("No Compatible Shader Provided\n");
				break;
			}
		}

		uint Shader::getUniformLocation(const string & uniformName) {
			return glGetUniformLocation(this->mProgram, uniformName.c_str());
		}

		void Shader::setUniform(const string& uniform, const float & f) {
			glUniform1f(uniformLocations[uniform], f);
		}

		void Shader::setUniform(const string& uniform, const Vector2 & v) {
			glUniform2fv(uniformLocations[uniform], 1, v);
		}

		void Shader::setUniform(const string& uniform, const Vector3 & v) {
			glUniform3fv(uniformLocations[uniform], 1, v);
		}

		void Shader::setUniform(const string& uniform, const Vector4 & v) {
			glUniform4fv(uniformLocations[uniform], 1, v);
		}

		void Shader::setUniform(const uint & uniform, const float & f) {
			glUniform1f(uniform, f);
		}

		void Shader::setUniform(const uint & uniform, const Vector2 & v) {
			glUniform2fv(uniform, 1, v);
		}

		void Shader::setUniform(const uint & uniform, const Vector3 & v) {
			glUniform3fv(uniform, 1, v);
		}

		void Shader::setUniform(const uint & uniform, const Vector4 & v) {
			glUniform4fv(uniform, 1, v);
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
				DPRINTLN(&ProgramErrorMessage[0]);
			}
		}

		void Shader::appendUniforms(const std::vector<String>& uniformNames) {
			
			for (size_t i = 0; i < uniformNames.size(); i++) {
				String uniformName = uniformNames[i];
				uint uniformLocation = this->getUniformLocation(uniformName);
				this->uniformLocations[uniformName] = uniformLocation;
			}
		}

		void Shader::bind() {
			glUseProgram(this->mProgram);
		}

		void Shader::unbind() {
			glUseProgram(0);
		}
		
		const Shader & Shader::operator=(const Shader & other) {

			mProgram = other.mProgram;
			fragment = other.fragment;
			vertex = other.vertex;

			uniformLocations.clear();
			uniformLocations.insert(other.uniformLocations.begin(), other.uniformLocations.end());
		}
	}
}

