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

		const Vector4& Vector4::operator=(const Vector4 & v)
		{
			this->x = v.x;
			this->x = v.x;
			this->x = v.x;
			this->x = v.x;
			return *this;
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

		std::ostream & operator<<(std::ostream & os, const Vector4 & u)
		{
			os << "Vector4 (" << u.x << ", " << u.y << ", " << u.z << ", " << u.w << ")";
			return os;
		}
	}
}