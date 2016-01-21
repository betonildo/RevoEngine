#pragma once
#include <src/Core/CoreService.h>

namespace revo {
	namespace adapter {
		class CoreServiceOpenGL : public CoreService
		{
		private:
			bool mHasInit;
		public:
			CoreServiceOpenGL();
			~CoreServiceOpenGL();

			// Inherited via CoreService
			virtual void initialize() override;
			virtual void setFlag(int * flagsArray, size_t flagsArraySize) override;
			virtual void terminate() override;			
			virtual bool hasInitialized() override;
		};
	}
}

