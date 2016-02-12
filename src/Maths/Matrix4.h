#pragma once
#include "Vector3.h"
#include "Vector4.h"

namespace revo {
	namespace maths {
		struct Matrix4 {
		private:
			union 
			{
				float elements[4][4];
				float _elements[4 * 4];
			};
			
		public:
			Matrix4();
			Matrix4(float diagonal);
			Matrix4(const Matrix4& other);
			~Matrix4();

			operator const float*() const;
			operator float*();



			// matrix4 operations
			static Matrix4 ortho(float left, float right, float bottom, float top, float near, float far);
			static Matrix4 perspective(float fieldOfView, float aspectRatio, float near, float far);
			

			// arithmetic by similar
			friend Matrix4 operator*(const Matrix4& m1, const Matrix4& m2);

			// arithmetic by vector3
			friend Vector3 operator*(const Matrix4& m1, const Vector3& v);

			// arithmetic by vector4
			friend Vector4 operator*(const Matrix4& m1, const Vector4& v);
		};
	}
}