#include "stdafx.h"
#include "Vector3.h"

namespace revo {
	namespace maths {
		Vector3::Vector3() {
			mVector[0] = mVector[1] = mVector[2] = 0;
		}

		Vector3::Vector3(float x, float y, float z) {
			mVector[0] = x;
			mVector[1] = y;
			mVector[2] = z;
		}

		Vector3::Vector3(const Vector3& other) {
			this->mVector[0] = other.mVector[0];
			this->mVector[1] = other.mVector[1];
			this->mVector[2] = other.mVector[2];
		}

		Vector3::~Vector3() {
			//not necessary dealloc memory because it is on stack
		}

		float& Vector3::x() {
			return mVector[0];
		}

		float& Vector3::y() {
			return mVector[1];
		}

		float& Vector3::z() {
			return mVector[2];
		}

		Vector3::operator const float*() const
		{
			return mVector;
		}
	}
}