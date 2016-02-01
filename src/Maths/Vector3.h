#pragma once
#include <iostream>

namespace revo {
	namespace maths {

		struct Vector3
		{
		private:
			float mVector[3];
		public:

			Vector3();
			Vector3(float x, float y, float z);
			Vector3(const Vector3& other);

			~Vector3();

			float& x();
			float& y();
			float& z();

			operator const float*() const;

			Vector3 normalize();


			///////////////////////////////////////////////////////////////////////////////
			////////// STATIC AREA ////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////



			static inline Vector3 Cross(const Vector3& u, const Vector3& v) {
				return Vector3(
					u.mVector[1] * v.mVector[2] - u.mVector[2] * v.mVector[1],
					u.mVector[2] * v.mVector[0] - u.mVector[0] * v.mVector[2],
					u.mVector[0] * v.mVector[1] - u.mVector[1] * v.mVector[0]
					);
			}

			static inline float Dot(const Vector3& u, const Vector3& v) {				
				return u.mVector[0] * v.mVector[0] + u.mVector[1] * v.mVector[1] + u.mVector[2] * v.mVector[2];
			}

			friend inline std::ostream& operator<<( std::ostream& os, const Vector3& u) {
				os << "Vector3 (" << u.mVector[0] << ", " << u.mVector[1] << ", " << u.mVector[2] << ")";
				return os;
			}

			friend inline Vector3 operator*(const Vector3& u, const float& f) {
				return Vector3(u.mVector[0] * f, u.mVector[1] * f, u.mVector[2] * f);
			}

			friend inline Vector3 operator*(const Vector3& u, const Vector3& v) {
				return Vector3(u.mVector[0] * v.mVector[0], u.mVector[1] * v.mVector[1], u.mVector[2] * v.mVector[2]);
			}

			friend inline Vector3 operator+(const Vector3& u, const Vector3& v) {
				return Vector3(u.mVector[0] + v.mVector[0], u.mVector[1] + v.mVector[1], u.mVector[2] + v.mVector[2]);
			}
		};
	}
}

