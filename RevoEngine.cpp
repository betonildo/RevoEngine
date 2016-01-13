// RevoEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RevoEngine.h"
#include "src/Core/Window.h"
#include "src/Core/WindowSDL2.h"


// This is an example of an exported variable
REVOENGINE_API int nRevoEngine=0;

// This is an example of an exported function.
REVOENGINE_API int fnRevoEngine(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see RevoEngine.h for the class definition
CRevoEngine::CRevoEngine()
{
	revo::Window::SetService(new revo::WindowSDL2());
	revo::Window* window = revo::Window::BuildService("Revo Engine Title", 800, 600);


	while (!window->Closed()) {

		window->Update();
	}

    return;
}
