#pragma once
namespace revo{
	namespace maths {
		struct Vector4
		{
		private:
			float mVector[4];
		public:
			Vector4();
			Vector4(float x, float y, float z, float w);
			Vector4(const Vector4& v);
			~Vector4();

			float& x();
			float& y();
			float& z();
			float& w();
		};
	}
}


