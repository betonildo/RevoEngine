#pragma once
#include "common_headers.h"
#include "ShaderComponent.h"
#include <src/Maths/Vector2.h>
#include <src/Maths/Vector3.h>
#include <src/Maths/Vector4.h>
#include <src/Utils/String.h>
#include <map>
#include <vector>

using namespace revo::maths;
using namespace revo::utils;

namespace revo {
	namespace graphics {
		class Shader
		{
		private:
			GLuint mProgram;			
			ShaderComponent fragment;
			ShaderComponent vertex;
			std::map<String, uint> uniformLocations;
			
			void logProgramErrors();
			void appendUniforms(const std::vector<String>& uniformNames);

		public:
			Shader();
			Shader(const Shader& other);
			~Shader();

			void attachComponent(uint BUFFER_TYPE, const string& shaderPath);
			uint getUniformLocation(const string& uniformName);
			void setUniform(const string& uniform, const float& f);
			void setUniform(const string& uniform, const Vector2& v);
			void setUniform(const string& uniform, const Vector3& v);
			void setUniform(const string& uniform, const Vector4& v);
			void setUniform(const uint& uniform, const float& f);
			void setUniform(const uint& uniform, const Vector2& v);
			void setUniform(const uint& uniform, const Vector3& v);
			void setUniform(const uint& uniform, const Vector4& v);
			void linkAll();
			void bind();
			void unbind();

			const Shader& operator=(const Shader& other);
		};
	}
}


