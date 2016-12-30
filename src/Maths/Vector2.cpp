#include "stdafx.h"
#include "Vector2.h"

namespace revo {
	namespace maths {
		Vector2::Vector2() :
			x(0), y(0)
		{
		}

		Vector2::Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2::Vector2(const Vector2 & v)
		{
			this->x = v.x;
			this->y = v.y;
		}

		Vector2::~Vector2()
		{
			// do something good here
		}

		Vector2::operator const float*() const
		{
			return &x;
		}

		Vector2::operator float*()
		{
			return &x;
		}

		Vector2 Vector2::operator=(const Vector2 & u)
		{
			this->x = u.x;
			this->y = u.y;
			return *this;
		}

		Vector2 operator+(const Vector2 & u, const Vector2 & v)
		{
			return Vector2(u.x + v.x, u.y + v.y);
		}

		Vector2 operator-(const Vector2 & u, const Vector2 & v)
		{
			return Vector2(u.x - v.x, u.y - v.y);
		}

		Vector2 operator*(const Vector2 & u, const Vector2 & v)
		{
			return Vector2(u.x * v.x, u.y * v.y);
		}

		Vector2 operator/(const Vector2 & u, const Vector2 & v)
		{
			return Vector2(u.x / v.x, u.y / v.y);
		}

		std::ostream & operator<<(std::ostream & os, const Vector2 & u)
		{
			os << "Vector2 (" << u.x << ", " << u.y << ")";
			return os;
		}
	}
}