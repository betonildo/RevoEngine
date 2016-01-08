// RevoEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RevoEngine.h"


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
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Not Initialized!" << std::endl;
	}

	glewExperimental = true;
	if (!glewInit()) {
		std::cout << "Glew Not initialized!" << std::endl;
	}

	// Window mode MUST include SDL_WINDOW_OPENGL for use with OpenGL.
	SDL_Window *window = SDL_CreateWindow(
		"SDL2/OpenGL Demo", 0, 0, 640, 480,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	// Create an OpenGL context associated with the window.
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);


	bool running = true;

	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			}
		}

		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}

	SDL_Delay(2000);
	SDL_Quit();
    return;
}
