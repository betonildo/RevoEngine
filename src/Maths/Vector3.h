#pragma once
#include <iostream>

namespace revo {
	namespace maths {
		class Vector3 {

		public:
			float x, y, z;

			Vector3();
			Vector3(float x, float y, float z);
			Vector3(const Vector3& v);
			~Vector3();

			operator const float*() const;
			operator float*();

			const Vector3& operator=(const Vector3& v);
			friend Vector3 operator+(const Vector3& u, const Vector3& v);
			friend Vector3 operator-(const Vector3& u, const Vector3& v);
			friend Vector3 operator*(const Vector3& u, const Vector3& v);
			friend Vector3 operator/(const Vector3& u, const Vector3& v);
			friend std::ostream& operator<<(std::ostream& os, const Vector3& u);
		};
	}
}