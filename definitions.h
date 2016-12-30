#pragma once
#define SDL2
#define GLEW
#define DEBUG

#ifdef GLEW
	#include <GL\glew.h>
	#define VERTEXSHADER GL_VERTEX_SHADER
	#define FRAGMENTSHADER GL_FRAGMENT_SHADER
#endif

#ifdef SDL2
	#include <SDL_opengl.h>
	#include <SDL.h>
#endif

#ifdef DEBUG
	#include <string>
	#include <assert.h>
	#define DASSERT(CONDITION) assert(CONDITION)
	#define DPRINT(CONTENT) std::cout << CONTENT
	#define DPRINTLN(CONTENT) std::cout << CONTENT << std::endl
#else
	#define DASSERT(CONDITION)
	#define DPRINT(CONTENT)
	#define DPRINTLN(CONTENT)
#endif

// definitions
#ifndef mapGlDrawElements
	#define mapGlDrawElements(COUNT, MODE, TYPE, OFFSET) glDrawElements(MODE, COUNT, TYPE, OFFSET)	
#endif

#ifndef uint
	#define uint GLuint
#endif

#ifndef byte
	#define byte unsigned char
#endif