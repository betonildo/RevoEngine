#include "stdafx.h"
#include "Transform.h"

namespace revo {
	namespace actors {
		Transform::Transform()
		{
		}


		Transform::~Transform()
		{
		}
		const Matrix4x4 & Transform::getModelMatrix()
		{
			return this->modelMatrix;
		}
	}
}