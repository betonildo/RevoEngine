#include "stdafx.h"
#include "Vector2.h"

namespace revo {
	namespace maths {
		Vector2::Vector2()
		{
			mVector[0] = mVector[1] = 0;
		}

		Vector2::Vector2(float x, float y)
		{
			mVector[0] = x;
			mVector[1] = y;
		}

		Vector2::Vector2(const Vector2 & v)
		{
			mVector[0] = v.mVector[0];
			mVector[1] = v.mVector[1];
		}


		Vector2::~Vector2()
		{
		}

		float & Vector2::x()
		{
			return mVector[0];
		}

		float & Vector2::y()
		{
			return mVector[1];
		}
		Vector2::operator const float*() const
		{
			return mVector;
		}
	}
}