#include "stdafx.h"
#include "Matrix4x4.h"

namespace revo {
	namespace maths {
		Matrix4x4::Matrix4x4()
		{
			mMatrix[0] = mMatrix[5] = mMatrix[10] = mMatrix[15] = 1;
			mMatrix[1] = mMatrix[2] = mMatrix[3] = mMatrix[4] = 0;
			mMatrix[6] = mMatrix[7] = mMatrix[8] = mMatrix[9] = 0;
			mMatrix[11] = mMatrix[12] = mMatrix[13] = mMatrix[14] = 0;
		}

		Matrix4x4::Matrix4x4(float mainColunmValue)
		{
			mMatrix[0] = mMatrix[5] = mMatrix[10] = mMatrix[15] = mainColunmValue;
			mMatrix[1] = mMatrix[2] = mMatrix[3] = mMatrix[4] = 0;
			mMatrix[6] = mMatrix[7] = mMatrix[8] = mMatrix[9] = 0;
			mMatrix[11] = mMatrix[12] = mMatrix[13] = mMatrix[14] = 0;
		}

		Matrix4x4::Matrix4x4(const Matrix4x4 & om)
		{
			mMatrix[0] = om.mMatrix[0];
			mMatrix[1] = om.mMatrix[1];
			mMatrix[2] = om.mMatrix[2];
			mMatrix[3] = om.mMatrix[3];
			mMatrix[4] = om.mMatrix[4];
			mMatrix[5] = om.mMatrix[5];
			mMatrix[6] = om.mMatrix[6];
			mMatrix[7] = om.mMatrix[7];
			mMatrix[8] = om.mMatrix[8];
			mMatrix[9] = om.mMatrix[9];
			mMatrix[10] = om.mMatrix[10];
			mMatrix[11] = om.mMatrix[11];
			mMatrix[12] = om.mMatrix[12];
			mMatrix[13] = om.mMatrix[13];
			mMatrix[14] = om.mMatrix[14];
			mMatrix[15] = om.mMatrix[15];
		}


		Matrix4x4::~Matrix4x4()
		{
		}

		float * Matrix4x4::operator[](uint index)
		{
			return (mMatrix + (index * 4));
		}

		float & Matrix4x4::operator()(uint i, uint j)
		{
			return mMatrix[i * 4 + j];
		}
	}
}
