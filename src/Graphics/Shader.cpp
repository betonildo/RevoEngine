#include "stdafx.h"
#include "Shader.h"

using namespace std;

namespace revo {
	namespace graphics {
		Shader::Shader()
		{
		}


		Shader::~Shader()
		{
		}
		void Shader::simpleLoad(const char * vertPath, const char * fragPath)
		{

			// Create the shaders
			GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
			GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

			// Read the Vertex Shader code from the file
			std::string VertexShaderCode = revo::utils::File::readAllText(vertPath);

			// Read the Fragment Shader code from the file
			std::string FragmentShaderCode = revo::utils::File::readAllText(fragPath);



			GLint Result = GL_FALSE;
			int InfoLogLength;



			// Compile Vertex Shader
			printf("Compiling shader : %s\n", vertPath);
			char const * VertexSourcePointer = VertexShaderCode.c_str();
			glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
			glCompileShader(VertexShaderID);

			// Check Vertex Shader
			glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0) {
				std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
				glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
				printf("%s\n", &VertexShaderErrorMessage[0]);

			}



			// Compile Fragment Shader
			printf("Compiling shader : %s\n", fragPath);
			char const * FragmentSourcePointer = FragmentShaderCode.c_str();
			glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
			glCompileShader(FragmentShaderID);

			// Check Fragment Shader
			glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0) {
				std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
				glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
				printf("%s\n", &FragmentShaderErrorMessage[0]);
			}



			// Link the program
			printf("Linking program\n");
			this->mProgram = glCreateProgram();
			glAttachShader(this->mProgram, VertexShaderID);
			glAttachShader(this->mProgram, FragmentShaderID);
			glLinkProgram(this->mProgram);

			// Check the program
			glGetProgramiv(this->mProgram, GL_LINK_STATUS, &Result);
			glGetProgramiv(this->mProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0) {
				std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
				glGetProgramInfoLog(this->mProgram, InfoLogLength, NULL, &ProgramErrorMessage[0]);
				printf("%s\n", &ProgramErrorMessage[0]);
			}

			glDeleteShader(VertexShaderID);
			glDeleteShader(FragmentShaderID);
		}

		void Shader::simpleUse()
		{
			glUseProgram(this->mProgram);
		}
	}
}

