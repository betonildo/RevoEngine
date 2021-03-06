// RevoEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RevoEngine.h"
#include "src/Core/Containers/Array.h"
#include "src/Maths/Vector2.h"
#include "src/Maths/Vector3.h"

// This is the constructor of a class that has been exported.
// see RevoEngine.h for the class definition
CRevoEngine::CRevoEngine()
{

	mServices.setWindowService(new revo::adapter::WindowSDL2());
	

    return;
}

void CRevoEngine::initSystem()
{

	mServices.initCoreService(new revo::adapter::CoreServiceSDL2());
	
	mWindow = mServices.createWindow("RevoEngine", 800, 600, revo::Flags::Window::OpenGL);
	
	mServices.initCoreService(new revo::adapter::CoreServiceOpenGL());
	mServices.initCoreService(new revo::adapter::CoreServiceGLEW());
}

void CRevoEngine::handleUpdate(std::function<void()> onUpdate)
{
	mOnUpdate = onUpdate;
}

int CRevoEngine::run()
{
	using namespace revo::maths;
	using namespace revo::utils;
	using namespace revo::graphics;
	using namespace revo::core::containers;

	static const float triangle[] = {
		//x		y	  z
		-1.0f, -1.0f, 0.0f,		
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};

	Array<Vector3, 3> triangle_arr;

	triangle_arr.Memcopy((void*)triangle);

	static const unsigned short elements[] = {
		0, 1, 2,
	};

	// Dark blue background
	glClearColor(0.0f, 1.0f, 0.0f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);

	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	uint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, triangle_arr.ByteSize(), triangle_arr.Elements(), GL_STATIC_DRAW);

	uint elementBuffer;
	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	std::string executablePath = std::string(SDL_GetBasePath());
	std::string vertShaderPath = executablePath + "DefaultResources/Shaders/Simple/Simple.vert";
	std::string fragShaderPath = executablePath + "DefaultResources/Shaders/Simple/Simple.frag";

	Shader shader;
	shader.attachComponent(VERTEXSHADER, vertShaderPath);
	shader.attachComponent(FRAGMENTSHADER, fragShaderPath);
	shader.linkAll();
	
	Vector4 color(0.5f, 0.5f, 0.5f, 1.0f);
	uint colorMult = shader.getUniformLocation("colorMult");

	while (!mWindow->closed()) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		shader.bind();
	
		// uniforms need to be set every time we bind a shader ( both below works correctly)
		shader.setUniform(colorMult, color);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		// Index buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);

		glDisableVertexAttribArray(0);

		shader.unbind();

		if (mOnUpdate) mOnUpdate();
		mWindow->update();
	}

	mServices.terminateCoreServices();

	return 0;
}
