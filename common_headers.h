#pragma once

//defines
#include <definitions.h>

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

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
#include <src\Graphics\ShaderComponent.h>

// maths
#include <src\Maths\Vector2.h>
#include <src\Maths\Vector3.h>
#include <src\Maths\Vector4.h>

// utils
#include <src\Utils\File.h>
#include <src\Utils\GLErrorCheck.h>

