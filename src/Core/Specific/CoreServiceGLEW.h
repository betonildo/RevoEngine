#pragma once
#include <GL\glew.h>
#include <src\Core\CoreService.h>

namespace revo {
	namespace adapter {
		class CoreServiceGLEW : public CoreService
		{
		private:
			bool mHasInit;
		public:
			CoreServiceGLEW();
			~CoreServiceGLEW();

			// Inherited via CoreService
			virtual void initialize() override;
			virtual void setFlag(int * flagsArray, size_t flagsArraySize) override;
			virtual void terminate() override;
			virtual bool hasInitialized() override;
		};
	}
}

