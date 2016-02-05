#pragma once
#include <iostream>

namespace revo {
	namespace maths {
		struct Vector4 {
			float x, y, z, w;

			Vector4();
			Vector4(float x, float y, float z, float w);
			Vector4(const Vector4& v);
			~Vector4();

			operator const float*() const;
			operator float*();

			friend Vector4 operator+(const Vector4& u, const Vector4& v);
			friend Vector4 operator-(const Vector4& u, const Vector4& v);
			friend Vector4 operator*(const Vector4& u, const Vector4& v);
			friend Vector4 operator/(const Vector4& u, const Vector4& v);
			friend std::ostream& operator<<(std::ostream& os, const Vector4& u);
		};
	}
}