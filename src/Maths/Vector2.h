#pragma once

#include <math.h>
#include <iostream>

namespace revo {
	namespace maths {
		struct Vector2 {
			float x, y;

			Vector2();
			Vector2(float x, float y);
			Vector2(const Vector2& v);
			~Vector2();

			operator const float*() const;
			operator float*();

			// vector operations
			float magnitude() const;
			float dot(const Vector2& other) const;
			float distance(const Vector2& other) const;
			Vector2 normalized();

			// arithmetics default call on this instance
			Vector2& add(const Vector2& other);
			Vector2& subtract(const Vector2& other);
			Vector2& multiply(const Vector2& other);
			Vector2& divide(const Vector2& other);

			// arithmetics by similar on this instance
			Vector2& operator+=(const Vector2& other);
			Vector2& operator-=(const Vector2& other);
			Vector2& operator*=(const Vector2& other);
			Vector2& operator/=(const Vector2& other);

			// arithmetics by similar
			friend Vector2 operator+(const Vector2& u, const Vector2& v);
			friend Vector2 operator-(const Vector2& u, const Vector2& v);
			friend Vector2 operator*(const Vector2& u, const Vector2& v);			
			friend Vector2 operator/(const Vector2& u, const Vector2& v);

			// arithmetics by scalar
			friend Vector2 operator+(const Vector2& u, const float& scalar);
			friend Vector2 operator-(const Vector2& u, const float& scalar);
			friend Vector2 operator*(const Vector2& u, const float& scalar);
			friend Vector2 operator/(const Vector2& u, const float& scalar);

			// boolean by similar
			friend bool operator==(const Vector2& u, const Vector2& v);
			friend bool operator!=(const Vector2& u, const Vector2& v);
			

			friend std::ostream& operator<<(std::ostream& os, const Vector2& u);
		};
	}
}