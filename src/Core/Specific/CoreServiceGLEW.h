#pragma once
#include <GL\glew.h>
#include <src\Core\CoreService.h>

namespace revo {
	namespace adapter {
		class CoreServiceGLEW : public CoreService
		{
		public:
			CoreServiceGLEW();
			~CoreServiceGLEW();

			// Inherited via CoreService
			virtual void initialize() override;
			virtual void terminate() override;

		};
	}
}

