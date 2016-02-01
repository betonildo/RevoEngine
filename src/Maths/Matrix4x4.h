#pragma once
#include <iostream>
#include "definitions.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace revo {
	namespace maths {
		struct Matrix4x4
		{
		private:
			float mMatrix[16];
		public:
			Matrix4x4();
			Matrix4x4(float mainColunmValue);
			Matrix4x4(const Matrix4x4& om);
			~Matrix4x4();

			float* operator[](uint index);
			float& operator()(uint i, uint j);
			
			static inline friend Vector3 operator*(const Matrix4x4& m, Vector3& u) {
				return Vector3(
					m.mMatrix[0] * u.x() + m.mMatrix[1] * u.y() + m.mMatrix[2] * u.z() + m.mMatrix[3],
					m.mMatrix[4] * u.x() + m.mMatrix[5] * u.y() + m.mMatrix[6] * u.z() + m.mMatrix[7],
					m.mMatrix[8] * u.x() + m.mMatrix[9] * u.y() + m.mMatrix[10] * u.z() + m.mMatrix[11]);
			}

			static inline friend Vector4 operator*(const Matrix4x4& m, Vector4& u) {
				return Vector4(
					m.mMatrix[0] * u.x() + m.mMatrix[1] * u.y() + m.mMatrix[2] * u.z() + m.mMatrix[3] * u.w(),
					m.mMatrix[4] * u.x() + m.mMatrix[5] * u.y() + m.mMatrix[6] * u.z() + m.mMatrix[7] * u.w(),
					m.mMatrix[8] * u.x() + m.mMatrix[9] * u.y() + m.mMatrix[10] * u.z() + m.mMatrix[11] * u.w(),
					m.mMatrix[12] * u.x() + m.mMatrix[13] * u.y() + m.mMatrix[14] * u.z() + m.mMatrix[15] * u.w());
			}

			static inline friend Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2) {
				
				Matrix4x4 mr;

				//line 1
				mr.mMatrix[0] = m1.mMatrix[0] * m2.mMatrix[0] + m1.mMatrix[1] * m2.mMatrix[4] + m1.mMatrix[2] * m2.mMatrix[8] + m1.mMatrix[3] * m2.mMatrix[12];
				mr.mMatrix[1] = m1.mMatrix[0] * m2.mMatrix[1] + m1.mMatrix[1] * m2.mMatrix[5] + m1.mMatrix[2] * m2.mMatrix[9] + m1.mMatrix[3] * m2.mMatrix[13];
				mr.mMatrix[2] = m1.mMatrix[0] * m2.mMatrix[2] + m1.mMatrix[1] * m2.mMatrix[6] + m1.mMatrix[2] * m2.mMatrix[10] + m1.mMatrix[3] * m2.mMatrix[14];
				mr.mMatrix[3] = m1.mMatrix[0] * m2.mMatrix[3] + m1.mMatrix[1] * m2.mMatrix[7] + m1.mMatrix[2] * m2.mMatrix[11] + m1.mMatrix[3] * m2.mMatrix[15];

				//line 2
				mr.mMatrix[4] = m1.mMatrix[4] * m2.mMatrix[0] + m1.mMatrix[5] * m2.mMatrix[4] + m1.mMatrix[6] * m2.mMatrix[8] + m1.mMatrix[7] * m2.mMatrix[12];
				mr.mMatrix[5] = m1.mMatrix[4] * m2.mMatrix[1] + m1.mMatrix[5] * m2.mMatrix[5] + m1.mMatrix[6] * m2.mMatrix[9] + m1.mMatrix[7] * m2.mMatrix[13];
				mr.mMatrix[6] = m1.mMatrix[4] * m2.mMatrix[2] + m1.mMatrix[5] * m2.mMatrix[6] + m1.mMatrix[6] * m2.mMatrix[10] + m1.mMatrix[7] * m2.mMatrix[14];
				mr.mMatrix[7] = m1.mMatrix[4] * m2.mMatrix[3] + m1.mMatrix[5] * m2.mMatrix[7] + m1.mMatrix[6] * m2.mMatrix[11] + m1.mMatrix[7] * m2.mMatrix[15];

				//line 3
				mr.mMatrix[8] = m1.mMatrix[8] * m2.mMatrix[0] + m1.mMatrix[9] * m2.mMatrix[4] + m1.mMatrix[10] * m2.mMatrix[8] + m1.mMatrix[11] * m2.mMatrix[12];
				mr.mMatrix[9] = m1.mMatrix[8] * m2.mMatrix[1] + m1.mMatrix[9] * m2.mMatrix[5] + m1.mMatrix[10] * m2.mMatrix[9] + m1.mMatrix[11] * m2.mMatrix[13];
				mr.mMatrix[10] = m1.mMatrix[8] * m2.mMatrix[2] + m1.mMatrix[9] * m2.mMatrix[6] + m1.mMatrix[10] * m2.mMatrix[10] + m1.mMatrix[11] * m2.mMatrix[14];
				mr.mMatrix[11] = m1.mMatrix[8] * m2.mMatrix[3] + m1.mMatrix[9] * m2.mMatrix[7] + m1.mMatrix[10] * m2.mMatrix[11] + m1.mMatrix[11] * m2.mMatrix[15];

				//line 4
				mr.mMatrix[12] = m1.mMatrix[12] * m2.mMatrix[0] + m1.mMatrix[13] * m2.mMatrix[4] + m1.mMatrix[14] * m2.mMatrix[8] + m1.mMatrix[15] * m2.mMatrix[12];
				mr.mMatrix[13] = m1.mMatrix[12] * m2.mMatrix[1] + m1.mMatrix[13] * m2.mMatrix[5] + m1.mMatrix[14] * m2.mMatrix[9] + m1.mMatrix[15] * m2.mMatrix[13];
				mr.mMatrix[14] = m1.mMatrix[12] * m2.mMatrix[2] + m1.mMatrix[13] * m2.mMatrix[6] + m1.mMatrix[14] * m2.mMatrix[10] + m1.mMatrix[15] * m2.mMatrix[14];
				mr.mMatrix[15] = m1.mMatrix[12] * m2.mMatrix[3] + m1.mMatrix[13] * m2.mMatrix[7] + m1.mMatrix[14] * m2.mMatrix[11] + m1.mMatrix[15] * m2.mMatrix[15];
				return mr;
			}

			friend inline std::ostream& operator<<(std::ostream& os, const Matrix4x4& m) {

				os << m.mMatrix[0] << " " << m.mMatrix[1] << " " << m.mMatrix[2] << " " << m.mMatrix[3] << std::endl;
				os << m.mMatrix[4] << " " << m.mMatrix[5] << " " << m.mMatrix[6] << " " << m.mMatrix[7] << std::endl;
				os << m.mMatrix[8] << " " << m.mMatrix[9] << " " << m.mMatrix[10]<< " " << m.mMatrix[11]<< std::endl;
				os << m.mMatrix[12]<< " " << m.mMatrix[13]<< " " << m.mMatrix[14]<< " " << m.mMatrix[15]<< std::endl;
					
				return os;
			}
		};
	}
}

