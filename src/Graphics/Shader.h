#pragma once
#include "common_headers.h"
#include "ShaderComponent.h"

namespace revo {
	namespace graphics {
		class Shader
		{
		private:
			GLuint mProgram;
			void logProgramErrors();
			ShaderComponent fragment;
			ShaderComponent vertex;


		public:
			Shader();
			~Shader();

			void attachComponent(uint BUFFER_TYPE, const string& shaderPath);
			void linkAll();
			void bind();
			void unbind();			
		};
	}
}


