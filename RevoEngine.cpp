// RevoEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RevoEngine.h"

// This is the constructor of a class that has been exported.
// see RevoEngine.h for the class definition
CRevoEngine::CRevoEngine()
{
	mServices.addCoreService(new revo::adapter::CoreServiceSDL2());
	mServices.addCoreService(new revo::adapter::CoreServiceOpenGL());
	
		
	
	mServices.setWindowService(new revo::adapter::WindowSDL2());
	mServices.setContext(new revo::adapter::ContextOpenGL());

    return;
}

void CRevoEngine::initSystem()
{
	mServices.initCoreServices();
	mWindow = mServices.createWindow("RevoEngine", 800, 600, revo::Flags::Window::OpenGL | revo::Flags::Window::FullScreen);

	mServices.initCoreService(new revo::adapter::CoreServiceGLEW());

}

void CRevoEngine::handleUpdate(std::function<void()> onUpdate)
{
	mOnUpdate = onUpdate;
}

int CRevoEngine::run()
{
	revo::Context* gl = mServices.getContext();

	GLfloat box[] = {
		-0.5f, -0.5f,
		-0.5f, 0.5f,
		0.5f, 0.5f,
		0.5f, -0.5f
	};

	unsigned short elements[] = {
		0, 1, 2,
		0, 2, 3
	};

	// Dark blue background
	glClearColor(0.0f, 1.0f, 0.0f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);


	uint vertexBuffer = gl->generateBuffer();
	gl->bindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	gl->bufferData(GL_ARRAY_BUFFER, sizeof(box) / sizeof(GLfloat), box);

	uint elementBuffer = gl->generateBuffer();
	gl->bindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	gl->bufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements) / sizeof(unsigned short), elements);

	while (!mWindow->closed()) {
		if (mOnUpdate) mOnUpdate();
		mWindow->update();
		
		glClear(GL_COLOR_BUFFER_BIT);
	}

	mServices.terminateCoreServices();

	return 0;
}
