#include "stdafx.h"
#include "Matrix4.h"

namespace revo {
	namespace maths {
		Matrix4::Matrix4()
		{
			for (int i = 0; i < 16; i++) {
				this->_e[i] = 0;
			}
		}

		Matrix4::Matrix4(float diagonal)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					this->elements[i][j] = i == j ? diagonal : 0;
				}
			}
		}

		Matrix4::Matrix4(const Matrix4 & other)
		{
			for (int i = 0; i < 16; i++) {
				this->_e[i] = other._e[i];
			}
		}

		Matrix4::~Matrix4()
		{
			// all alocated on stack, no manual free
		}

		Matrix4::operator const float*() const
		{
			return this->_e;
		}

		Matrix4::operator float*()
		{
			return this->_e;
		}

		Matrix4 Matrix4::ortho(float left, float right, float bottom, float top, float near_plane, float far_plane)
		{
			Matrix4 res;
			el(res, 0, 0) = 2 / (right - left);
			el(res, 1, 1) = 2 / (top - bottom);
			el(res, 2, 2) = -2 / (far_plane - near_plane);
			el(res, 3, 3) = 1;

			el(res, 0, 3) = -((right + left) / (right - left));
			el(res, 1, 3) = -((top + bottom) / (top - bottom));
			el(res, 2, 3) = -((far_plane + near_plane) / (far_plane - near_plane));
			return res;
		}

		Matrix4 Matrix4::perspective(float fieldOfView, float aspectRatio, float near_plane, float far_plane)
		{
			Matrix4 res;
			float Scale = 1 / tan(fieldOfView * 0.5 * M_PI / 180);
			el(res, 0, 0) = Scale; // scale the x coordinates of the projected point 
			el(res, 1, 1) = Scale; // scale the y coordinates of the projected point 
			el(res, 2, 2) = -far_plane / (far_plane - near_plane); // used to remap z to [0,1] 
			el(res, 3, 2) = -far_plane * near_plane / (far_plane - near_plane); // used to remap z [0,1] 
			el(res, 2, 3) = -1; // set w = -z 
			el(res, 3, 3) = 0;
			return res;
		}

		Matrix4 operator*(const Matrix4 & m1, const Matrix4 & m2)
		{
			Matrix4 res;
			// response			/////        ELEMENT 0		 //////	  ////////   ELEMENT 1		////////	/////		ELEMENT 2		//////	  ////////    ELEMENT 3			/////
			res._e[0 + 0 * 4] = m1._e[0 + 0 * 4] * m2._e[0 + 0 * 4] + m1._e[0 + 1 * 4] * m2._e[1 + 0 * 4] + m1._e[0 + 2 * 4] * m2._e[2 + 0 * 4] + m1._e[0 + 3 * 4] * m2._e[3 + 0 * 4];
			res._e[0 + 1 * 4] = m1._e[0 + 0 * 4] * m2._e[0 + 1 * 4] + m1._e[0 + 1 * 4] * m2._e[1 + 1 * 4] + m1._e[0 + 2 * 4] * m2._e[2 + 1 * 4] + m1._e[0 + 3 * 4] * m2._e[3 + 1 * 4];
			res._e[0 + 2 * 4] = m1._e[0 + 0 * 4] * m2._e[0 + 2 * 4] + m1._e[0 + 1 * 4] * m2._e[1 + 2 * 4] + m1._e[0 + 2 * 4] * m2._e[2 + 2 * 4] + m1._e[0 + 3 * 4] * m2._e[3 + 2 * 4];
			res._e[0 + 3 * 4] = m1._e[0 + 0 * 4] * m2._e[0 + 3 * 4] + m1._e[0 + 1 * 4] * m2._e[1 + 3 * 4] + m1._e[0 + 2 * 4] * m2._e[2 + 3 * 4] + m1._e[0 + 3 * 4] * m2._e[3 + 3 * 4];

			res._e[1 + 0 * 4] = m1._e[1 + 0 * 4] * m2._e[0 + 0 * 4] + m1._e[1 + 1 * 4] * m2._e[1 + 0 * 4] + m1._e[1 + 2 * 4] * m2._e[2 + 0 * 4] + m1._e[1 + 3 * 4] * m2._e[3 + 0 * 4];
			res._e[1 + 1 * 4] = m1._e[1 + 0 * 4] * m2._e[0 + 1 * 4] + m1._e[1 + 1 * 4] * m2._e[1 + 1 * 4] + m1._e[1 + 2 * 4] * m2._e[2 + 1 * 4] + m1._e[1 + 3 * 4] * m2._e[3 + 1 * 4];
			res._e[1 + 2 * 4] = m1._e[1 + 0 * 4] * m2._e[0 + 2 * 4] + m1._e[1 + 1 * 4] * m2._e[1 + 2 * 4] + m1._e[1 + 2 * 4] * m2._e[2 + 2 * 4] + m1._e[1 + 3 * 4] * m2._e[3 + 2 * 4];
			res._e[1 + 3 * 4] = m1._e[1 + 0 * 4] * m2._e[0 + 3 * 4] + m1._e[1 + 1 * 4] * m2._e[1 + 3 * 4] + m1._e[1 + 2 * 4] * m2._e[2 + 3 * 4] + m1._e[1 + 3 * 4] * m2._e[3 + 3 * 4];

			res._e[2 + 0 * 4] = m1._e[2 + 0 * 4] * m2._e[0 + 0 * 4] + m1._e[2 + 1 * 4] * m2._e[1 + 0 * 4] + m1._e[2 + 2 * 4] * m2._e[2 + 0 * 4] + m1._e[2 + 3 * 4] * m2._e[3 + 0 * 4];
			res._e[2 + 1 * 4] = m1._e[2 + 0 * 4] * m2._e[0 + 1 * 4] + m1._e[2 + 1 * 4] * m2._e[1 + 1 * 4] + m1._e[2 + 2 * 4] * m2._e[2 + 1 * 4] + m1._e[2 + 3 * 4] * m2._e[3 + 1 * 4];
			res._e[2 + 2 * 4] = m1._e[2 + 0 * 4] * m2._e[0 + 2 * 4] + m1._e[2 + 1 * 4] * m2._e[1 + 2 * 4] + m1._e[2 + 2 * 4] * m2._e[2 + 2 * 4] + m1._e[2 + 3 * 4] * m2._e[3 + 2 * 4];
			res._e[2 + 3 * 4] = m1._e[2 + 0 * 4] * m2._e[0 + 3 * 4] + m1._e[2 + 1 * 4] * m2._e[1 + 3 * 4] + m1._e[2 + 2 * 4] * m2._e[2 + 3 * 4] + m1._e[2 + 3 * 4] * m2._e[3 + 3 * 4];

			res._e[3 + 0 * 4] = m1._e[3 + 0 * 4] * m2._e[0 + 0 * 4] + m1._e[3 + 1 * 4] * m2._e[1 + 0 * 4] + m1._e[3 + 2 * 4] * m2._e[2 + 0 * 4] + m1._e[3 + 3 * 4] * m2._e[3 + 0 * 4];
			res._e[3 + 1 * 4] = m1._e[3 + 0 * 4] * m2._e[0 + 1 * 4] + m1._e[3 + 1 * 4] * m2._e[1 + 1 * 4] + m1._e[3 + 2 * 4] * m2._e[2 + 1 * 4] + m1._e[3 + 3 * 4] * m2._e[3 + 1 * 4];
			res._e[3 + 2 * 4] = m1._e[3 + 0 * 4] * m2._e[0 + 2 * 4] + m1._e[3 + 1 * 4] * m2._e[1 + 2 * 4] + m1._e[3 + 2 * 4] * m2._e[2 + 2 * 4] + m1._e[3 + 3 * 4] * m2._e[3 + 2 * 4];
			res._e[3 + 3 * 4] = m1._e[3 + 0 * 4] * m2._e[0 + 3 * 4] + m1._e[3 + 1 * 4] * m2._e[1 + 3 * 4] + m1._e[3 + 2 * 4] * m2._e[2 + 3 * 4] + m1._e[3 + 3 * 4] * m2._e[3 + 3 * 4];

			return res;
		}

		Vector3 operator*(const Matrix4 & m1, const Vector3 & v)
		{
			Vector3 r;

			float fInvW = 1.0f / (m1._e[3 + 0 * 4] * v.x + m1._e[3 + 1 * 4] * v.y + m1._e[3 + 2 * 4] * v.z + m1._e[3 + 3 * 4]);

			r.x = (m1._e[0 + 0 * 4] * v.x + m1._e[0 + 1 * 4] * v.y + m1._e[0 + 2 * 4] * v.z + m1._e[0 + 3 * 4]) * fInvW;
			r.y = (m1._e[1 + 0 * 4] * v.x + m1._e[1 + 1 * 4] * v.y + m1._e[1 + 2 * 4] * v.z + m1._e[1 + 3 * 4]) * fInvW;
			r.z = (m1._e[2 + 0 * 4] * v.x + m1._e[2 + 1 * 4] * v.y + m1._e[2 + 2 * 4] * v.z + m1._e[2 + 3 * 4]) * fInvW;

			return r;
		}

		Vector4 operator*(const Matrix4 & m1, const Vector4 & v)
		{
			return Vector4(	m1._e[0 + 0 * 4] * v.x + m1._e[0 + 1 * 4] * v.y + m1._e[0 + 2 * 4] * v.z + m1._e[0 + 3 * 4] * v.w,
							m1._e[1 + 0 * 4] * v.x + m1._e[1 + 1 * 4] * v.y + m1._e[1 + 2 * 4] * v.z + m1._e[1 + 3 * 4] * v.w,
							m1._e[2 + 0 * 4] * v.x + m1._e[2 + 1 * 4] * v.y + m1._e[2 + 2 * 4] * v.z + m1._e[2 + 3 * 4] * v.w,
							m1._e[3 + 0 * 4] * v.x + m1._e[3 + 1 * 4] * v.y + m1._e[3 + 2 * 4] * v.z + m1._e[3 + 3 * 4] * v.w);
		}
	}
}