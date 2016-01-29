#pragma once
#include <iostream>
#include "definitions.h"
#include "Vector2.h"
#include "Vector3.h"

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
			operator const float*() const;

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

