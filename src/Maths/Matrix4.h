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
				float _e[4 * 4];
			};
			
		public:
			Matrix4();
			Matrix4(float diagonal);
			Matrix4(const Matrix4& other);
			~Matrix4();

			operator const float*() const;
			operator float*();

			// matrix4 operations for self containing


			// matrix4 operations
			static Matrix4 ortho(float left, float right, float bottom, float top, float near_plane, float far_plane);
			static Matrix4 perspective(float fieldOfView, float aspectRatio, float near_plane, float far_plane);
			

			// arithmetic by similar
			friend Matrix4 operator*(const Matrix4& m1, const Matrix4& m2);

			// arithmetic by vector3
			friend Vector3 operator*(const Matrix4& m1, const Vector3& v);

			// arithmetic by vector4
			friend Vector4 operator*(const Matrix4& m1, const Vector4& v);

			//acces operator, converting internally to a transposed matrix like access method
			// Access to the reference of the element
			inline float& operator()(int i, int j){
				return _e[i + j * 4];
			}

			// access to the constant reference of the element
			inline const float& operator()(int i, int j) const {
				return _e[i + j * 4];
			}

			/// simple pre compiled access to elements
#define		el(m,i,j) m._e[i + j * 4]

		};
	}
}