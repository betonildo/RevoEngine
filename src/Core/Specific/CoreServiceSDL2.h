#pragma once
#include <SDL.h>
#include <src\Core\CoreService.h>

namespace revo {
	namespace adapter {

		class CoreServiceSDL2 : public CoreService
		{
		private:
			bool mHasInit;
		public:
			CoreServiceSDL2();
			~CoreServiceSDL2();

			// Inherited via CoreService
			virtual void initialize() override;
			virtual void setFlag(int * flagsArray, size_t flagsArraySize) override;
			virtual void terminate() override;
			virtual bool hasInitialized() override;
		};
	}
}

