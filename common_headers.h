#pragma once

#include <GL\glew.h>
#include <SDL_opengl.h>
#include <SDL.h>

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

//defines
#include <definitions.h>


#include <src\Core\ServiceProvider.h>
#include <src\Core\Window.h>
#include <src\Core\CoreService.h>

// specific "Adapter"
#include <src\Core\Specific\CoreServiceGLEW.h>
#include <src\Core\Specific\CoreServiceSDL2.h>
#include <src\Core\Specific\CoreServiceOpenGL.h>
#include <src\Core\Specific\WindowSDL2.h>
#include <src\Core\AdaptedEnumerations.h>

// graphics
#include <src\Graphics\Shader.h>


// utils
#include <src\Utils\File.h>
#include <src\Utils\GLErrorCheck.h>

