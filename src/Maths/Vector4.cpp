#include "stdafx.h"
#include "Vector4.h"

namespace revo {
	namespace maths {
		Vector4::Vector4() :
			x(0), y(0), z(0), w(0)
		{
		}

		Vector4::Vector4(float x, float y, float z, float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vector4::Vector4(const Vector4 & v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
		}

		Vector4::~Vector4()
		{
			// do something good here
		}

		Vector4::operator const float*() const
		{
			return &x;
		}

		Vector4::operator float*()
		{
			return &x;
		}

		float Vector4::magnitude() const
		{
			return sqrtf(x * x + y * y + z * z);
		}

		float Vector4::dot(const Vector4 & other) const
		{
			return x * other.x + y * other.y + z * other.z + w * other.w;
		}

		float Vector4::distance(const Vector4 & other) const
		{
			return ((*this) - other).magnitude();
		}

		Vector4 Vector4::normalized()
		{
			return (*this) * (1.0f / this->magnitude());
		}

		Vector4 Vector4::cross(const Vector4 & other)
		{
			return Vector4(
				y * other.z - z * other.y,
				z * other.x - x * other.z,
				x * other.y - y * other.x,
				1.0f
				);
		}

		Vector4 & Vector4::add(const Vector4 & other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
			return *this;
		}

		Vector4 & Vector4::subtract(const Vector4 & other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
			return *this;
		}

		Vector4 & Vector4::multiply(const Vector4 & other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
			return *this;
		}

		Vector4 & Vector4::divide(const Vector4 & other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
			return *this;
		}

		Vector4 & Vector4::operator+=(const Vector4 & other)
		{
			return this->add(other);
		}

		Vector4 & Vector4::operator-=(const Vector4 & other)
		{
			return this->subtract(other);
		}

		Vector4 & Vector4::operator*=(const Vector4 & other)
		{
			return this->multiply(other);
		}

		Vector4 & Vector4::operator/=(const Vector4 & other)
		{
			return this->divide(other);
		}

		Vector4 operator+(const Vector4 & u, const Vector4 & v)
		{
			return Vector4(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);
		}

		Vector4 operator-(const Vector4 & u, const Vector4 & v)
		{
			return Vector4(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);
		}

		Vector4 operator*(const Vector4 & u, const Vector4 & v)
		{
			return Vector4(u.x * v.x, u.y * v.y, u.z * v.z, u.w * v.w);
		}

		Vector4 operator/(const Vector4 & u, const Vector4 & v)
		{
			return Vector4(u.x / v.x, u.y / v.y, u.z / v.z, u.w / v.w);
		}

		Vector4 operator+(const Vector4 & u, const float & scalar)
		{
			return Vector4(u.x + scalar, u.y + scalar, u.z + scalar, u.w + scalar);
		}

		Vector4 operator-(const Vector4 & u, const float & scalar)
		{
			return Vector4(u.x - scalar, u.y - scalar, u.z - scalar, u.w - scalar);
		}

		Vector4 operator*(const Vector4 & u, const float & scalar)
		{
			return Vector4(u.x * scalar, u.y * scalar, u.z * scalar, u.w * scalar);
		}

		Vector4 operator/(const Vector4 & u, const float & scalar)
		{
			return Vector4(u.x / scalar, u.y / scalar, u.z / scalar, u.w / scalar);
		}


		bool operator==(const Vector4 & u, const Vector4 & v)
		{
			return u.x == v.x && u.y == v.y && u.z == v.z && u.w == v.w;
		}

		bool operator!=(const Vector4 & u, const Vector4 & v)
		{
			return !(u == v);
		}

		std::ostream & operator<<(std::ostream & os, const Vector4 & u)
		{
			os << "Vector4 (" << u.x << ", " << u.y << ", " << u.z << ", " << u.w << ")";
			return os;
		}
	}
}