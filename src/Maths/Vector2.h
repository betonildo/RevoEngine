#pragma once

#include <iostream>

namespace revo {
	namespace maths {
		class Vector2 {
		
		public:
			float x, y;

			Vector2();
			Vector2(float x, float y);
			Vector2(const Vector2& v);
			~Vector2();

			operator const float*() const;
			operator float*();

			Vector2 operator=(const Vector2& u);
			friend Vector2 operator+(const Vector2& u, const Vector2& v);
			friend Vector2 operator-(const Vector2& u, const Vector2& v);
			friend Vector2 operator*(const Vector2& u, const Vector2& v);
			friend Vector2 operator/(const Vector2& u, const Vector2& v);
			friend std::ostream& operator<<(std::ostream& os, const Vector2& u);
		};
	}
}