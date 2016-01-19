#pragma once
#include <SDL.h>
#include <src\Core\CoreService.h>

namespace revo {
	namespace adapter {

		class CoreServiceSDL2 : public CoreService
		{
		public:
			CoreServiceSDL2();
			~CoreServiceSDL2();

			// Inherited via CoreService
			virtual void initialize() override;
			virtual void terminate() override;
		};
	}
}

