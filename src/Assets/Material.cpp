#include "stdafx.h"
#include "Material.h"

namespace revo {
	namespace assets {

		void Material::attachShader(const Shader & shader) {

			m_shader = shader;
		}

		void Material::setFloat(const string & name, const float & f) {
			uniforms[name].f = f;
		}

		void Material::setVector(const string & name, const Vector2 & vec) {
			uniforms[name].vec2 = vec;
		}

		void Material::setVector(const string & name, const Vector3 & vec) {
			uniforms[name].vec3 = vec;
		}

		void Material::setVector(const string & name, const Vector4 & vec) {
			uniforms[name].vec4 = vec;
		}
		
		void Material::setTexture(const string & name, const Texture & texture)	{
			uniforms[name].texture = texture;
		}
		
		void Material::bindAllValues() {
			
			
		}
	}
}