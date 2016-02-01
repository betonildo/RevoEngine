#pragma once
#include "../Maths/Matrix4x4.h"
#include "../Maths/Vector3.h"

using namespace revo::maths;

namespace revo {
	namespace actors {
		class Transform
		{
		private:
			Matrix4x4 modelMatrix;

		public:
			Transform();
			~Transform();

			///////////////////////////////////////////////////////////////////////
			/// Transformations ///////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////

			void setLocalPosition(const Vector3& position);
			Vector3& getLocalPosition();

			void setLocalRotation(const Vector3& axe, float radius);
			


			const Matrix4x4& getModelMatrix();
		};
	}
}

