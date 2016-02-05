#pragma once

#include <math.h>
#include <iostream>

namespace revo {
	namespace maths {
		struct Vector3 {
			float x, y, z;

			Vector3();
			Vector3(float x, float y, float z);
			Vector3(const Vector3& v);
			~Vector3();

			operator const float*() const;
			operator float*();

			// vector operations
			float magnitude() const;
			float dot(const Vector3& other) const;
			float distance(const Vector3& other) const;
			Vector3 normalized();
			Vector3 cross(const Vector3& other);

			// arithmetics default call on this instance
			Vector3& add(const Vector3& other);
			Vector3& subtract(const Vector3& other);
			Vector3& multiply(const Vector3& other);
			Vector3& divide(const Vector3& other);

			// arithmetics by similar on this instance
			Vector3& operator+=(const Vector3& other);
			Vector3& operator-=(const Vector3& other);
			Vector3& operator*=(const Vector3& other);
			Vector3& operator/=(const Vector3& other);

			// arithmetics by similar
			friend Vector3 operator+(const Vector3& u, const Vector3& v);
			friend Vector3 operator-(const Vector3& u, const Vector3& v);
			friend Vector3 operator*(const Vector3& u, const Vector3& v);
			friend Vector3 operator/(const Vector3& u, const Vector3& v);

			// arithmetics by scalar
			friend Vector3 operator+(const Vector3& u, const float& scalar);
			friend Vector3 operator-(const Vector3& u, const float& scalar);
			friend Vector3 operator*(const Vector3& u, const float& scalar);
			friend Vector3 operator/(const Vector3& u, const float& scalar);

			// boolean by similar
			friend bool operator==(const Vector3& u, const Vector3& v);
			friend bool operator!=(const Vector3& u, const Vector3& v);


			friend std::ostream& operator<<(std::ostream& os, const Vector3& u);
		};
	}
}