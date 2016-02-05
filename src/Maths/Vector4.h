#pragma once

#include <math.h>
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

			// vector operations
			float magnitude() const;
			float dot(const Vector4& other) const;
			float distance(const Vector4& other) const;
			Vector4 normalized();
			Vector4 cross(const Vector4& other);

			// arithmetics default call on this instance
			Vector4& add(const Vector4& other);
			Vector4& subtract(const Vector4& other);
			Vector4& multiply(const Vector4& other);
			Vector4& divide(const Vector4& other);

			// arithmetics by similar on this instance
			Vector4& operator+=(const Vector4& other);
			Vector4& operator-=(const Vector4& other);
			Vector4& operator*=(const Vector4& other);
			Vector4& operator/=(const Vector4& other);

			// arithmetics by similar
			friend Vector4 operator+(const Vector4& u, const Vector4& v);
			friend Vector4 operator-(const Vector4& u, const Vector4& v);
			friend Vector4 operator*(const Vector4& u, const Vector4& v);
			friend Vector4 operator/(const Vector4& u, const Vector4& v);

			// arithmetics by scalar
			friend Vector4 operator+(const Vector4& u, const float& scalar);
			friend Vector4 operator-(const Vector4& u, const float& scalar);
			friend Vector4 operator*(const Vector4& u, const float& scalar);
			friend Vector4 operator/(const Vector4& u, const float& scalar);

			// boolean by similar
			friend bool operator==(const Vector4& u, const Vector4& v);
			friend bool operator!=(const Vector4& u, const Vector4& v);


			friend std::ostream& operator<<(std::ostream& os, const Vector4& u);
		};
	}
}