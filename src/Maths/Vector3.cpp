#include "stdafx.h"
#include "Vector3.h"

namespace revo {
	namespace maths {
		Vector3::Vector3() :
			x(0), y(0), z(0)
		{
		}

		Vector3::Vector3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3::Vector3(const Vector3 & v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
		}

		Vector3::~Vector3()
		{
			// do something good here
		}

		Vector3::operator const float*() const
		{
			return &x;
		}

		Vector3::operator float*()
		{
			return &x;
		}

		float Vector3::magnitude() const
		{
			return sqrtf(x * x + y * y + z * z);
		}

		float Vector3::dot(const Vector3 & other) const
		{
			return x * other.x + y * other.y + z * other.z;
		}

		float Vector3::distance(const Vector3 & other) const
		{
			return ((*this) - other).magnitude();
		}

		Vector3 Vector3::normalized()
		{
			return (*this) * (1.0f / this->magnitude());
		}

		Vector3 Vector3::cross(const Vector3 & other)
		{
			return Vector3(
				y * other.z - z * other.y,
				z * other.x - x * other.z,
				x * other.y - y * other.x
				);
		}

		Vector3 & Vector3::add(const Vector3 & other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}

		Vector3 & Vector3::subtract(const Vector3 & other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}

		Vector3 & Vector3::multiply(const Vector3 & other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return *this;
		}

		Vector3 & Vector3::divide(const Vector3 & other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			return *this;
		}

		Vector3 & Vector3::operator+=(const Vector3 & other)
		{
			return this->add(other);
		}

		Vector3 & Vector3::operator-=(const Vector3 & other)
		{
			return this->subtract(other);
		}

		Vector3 & Vector3::operator*=(const Vector3 & other)
		{
			return this->multiply(other);
		}

		Vector3 & Vector3::operator/=(const Vector3 & other)
		{
			return this->divide(other);
		}

		Vector3 operator+(const Vector3 & u, const Vector3 & v)
		{
			return Vector3(u.x + v.x, u.y + v.y, u.z + v.z);
		}

		Vector3 operator-(const Vector3 & u, const Vector3 & v)
		{
			return Vector3(u.x - v.x, u.y - v.y, u.z - v.z);
		}

		Vector3 operator*(const Vector3 & u, const Vector3 & v)
		{
			return Vector3(u.x * v.x, u.y * v.y, u.z * v.z);
		}

		Vector3 operator/(const Vector3 & u, const Vector3 & v)
		{
			return Vector3(u.x / v.x, u.y / v.y, u.z / v.z);
		}

		Vector3 operator+(const Vector3 & u, const float & scalar)
		{
			return Vector3(u.x + scalar, u.y + scalar, u.z + scalar);
		}

		Vector3 operator-(const Vector3 & u, const float & scalar)
		{
			return Vector3(u.x - scalar, u.y - scalar, u.z - scalar);
		}

		Vector3 operator*(const Vector3 & u, const float & scalar)
		{
			return Vector3(u.x * scalar, u.y * scalar, u.z * scalar);
		}

		Vector3 operator/(const Vector3 & u, const float & scalar)
		{
			return Vector3(u.x / scalar, u.y / scalar, u.z / scalar);
		}


		bool operator==(const Vector3 & u, const Vector3 & v)
		{
			return u.x == v.x && u.y == v.y && u.z == v.z;
		}

		bool operator!=(const Vector3 & u, const Vector3 & v)
		{
			return !(u == v);
		}

		std::ostream & operator<<(std::ostream & os, const Vector3 & u)
		{
			os << "Vector3 (" << u.x << ", " << u.y << ", " << u.z << ")";
			return os;
		}
	}
}