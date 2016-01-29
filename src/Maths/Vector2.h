#pragma once

#include <iostream>

namespace revo {
	namespace maths {
		struct Vector2
		{
		private:
			float mVector[2];
		public:
			Vector2();
			Vector2(float x, float y);
			Vector2(const Vector2& v);
			~Vector2();

			float& x();
			float& y();

			operator const float*() const;

			static inline float Dot(const Vector2& u, const Vector2& v) {
				return u.mVector[0] * v.mVector[0] + u.mVector[1] * v.mVector[1];
			}

			friend inline std::ostream& operator<<(std::ostream& os, const Vector2& u) {
				os << "Vector2 (" << u.mVector[0] << ", " << u.mVector[1] << ")";
				return os;
			}
		};
	}
}


