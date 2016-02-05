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

		float Vector2::magnitude() const
		{
			return sqrtf(x * x + y * y);
		}

		float Vector2::dot(const Vector2 & other) const
		{
			return x * other.x + y * other.y;
		}

		float Vector2::distance(const Vector2 & other) const
		{
			return ((*this) - other).magnitude();
		}

		Vector2 Vector2::normalized()
		{
			return (*this) * (1.0f / this->magnitude());
		}

		Vector2 & Vector2::add(const Vector2 & other)
		{
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

		Vector2 & Vector2::subtract(const Vector2 & other)
		{
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}

		Vector2 & Vector2::multiply(const Vector2 & other)
		{
			this->x *= other.x;
			this->y *= other.y;
			return *this;
		}

		Vector2 & Vector2::divide(const Vector2 & other)
		{
			this->x /= other.x;
			this->y /= other.y;
			return *this;
		}

		Vector2 & Vector2::operator+=(const Vector2 & other)
		{
			return this->add(other);
		}

		Vector2 & Vector2::operator-=(const Vector2 & other)
		{
			return this->subtract(other);
		}

		Vector2 & Vector2::operator*=(const Vector2 & other)
		{
			return this->multiply(other);
		}

		Vector2 & Vector2::operator/=(const Vector2 & other)
		{
			return this->divide(other);
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

		Vector2 operator+(const Vector2 & u, const float & scalar)
		{
			return Vector2(u.x + scalar, u.y + scalar);
		}

		Vector2 operator-(const Vector2 & u, const float & scalar)
		{
			return Vector2(u.x - scalar, u.y - scalar);
		}

		Vector2 operator*(const Vector2 & u, const float & scalar)
		{
			return Vector2(u.x * scalar, u.y * scalar);
		}

		Vector2 operator/(const Vector2 & u, const float & scalar)
		{
			return Vector2(u.x / scalar, u.y / scalar);
		}

		Vector2 operator/(const Vector2 & u, const Vector2 & v)
		{
			return Vector2(u.x / v.x, u.y / v.y);
		}

		bool operator==(const Vector2 & u, const Vector2 & v)
		{
			return u.x == v.x && u.y == v.y;
		}

		bool operator!=(const Vector2 & u, const Vector2 & v)
		{
			return !(u == v);
		}

		std::ostream & operator<<(std::ostream & os, const Vector2 & u)
		{
			os << "Vector2 (" << u.x << ", " << u.y << ")";
			return os;
		}
	}
}