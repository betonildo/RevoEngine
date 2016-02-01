#include "stdafx.h"
#include "Vector4.h"

namespace revo {
	namespace maths {
		Vector4::Vector4()
		{
		}

		Vector4::Vector4(float x, float y, float z, float w)
		{
			mVector[0] = x;
			mVector[1] = y;
			mVector[2] = z;
			mVector[3] = w;
		}

		Vector4::Vector4(const Vector4 & v)
		{
			mVector[0] = v.mVector[0];
			mVector[1] = v.mVector[1];
			mVector[2] = v.mVector[2];
			mVector[3] = v.mVector[3];
		}

		Vector4::~Vector4()
		{
		}

		float & Vector4::x()
		{
			return mVector[0];
		}

		float & Vector4::y()
		{
			return mVector[1];
		}

		float & Vector4::z()
		{
			return mVector[2];
		}

		float & Vector4::w()
		{
			return mVector[3];
		}
	}
}