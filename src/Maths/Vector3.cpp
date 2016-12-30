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

		const Vector3& Vector3::operator=(const Vector3 & v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
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

		std::ostream & operator<<(std::ostream & os, const Vector3 & u)
		{
			os << "Vector3 (" << u.x << ", " << u.y << ", " << u.z << ")";
			return os;
		}
	}
}