#pragma once
#include "common_headers.h"
#include <src/Graphics/Shader.h>
#include <src/Graphics/ShaderComponent.h>
#include <src/Maths/Vector2.h>
#include <src/Maths/Vector3.h>
#include <src/Maths/Vector4.h>
#include <src/Assets/Texture.h>
#include <map>

using namespace revo::graphics;

namespace revo {

	namespace assets {

		class Material {

		private:
			Shader m_shader;
			union UniformValues {
				float f;
				Vector2 vec2;
				Vector3 vec3;
				Vector4 vec4;
				Texture texture;
			};

			std::map<string, UniformValues> uniforms;

		public:
			void attachShader(const Shader& shader);
			void setFloat(const string& name, const float& f);
			void setVector(const string& name, const Vector2& vec);
			void setVector(const string& name, const Vector3& vec);
			void setVector(const string& name, const Vector4& vec);
			void setTexture(const string& name, const Texture& texture);
			void bindAllValues();
		};
	}
}