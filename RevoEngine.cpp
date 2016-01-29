// RevoEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RevoEngine.h"

using namespace revo::maths;

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

	Vector3 vertices[8] = {
		//x		y	  z
		Vector3(-0.5f, -0.5f, 0.5f),
		Vector3(0.5f, -0.5f, 0.5f),
		Vector3(0.5f, 0.5f, 0.5f),
		Vector3(-0.5f, 0.5f, 0.5f),
		Vector3(-0.5f, 0.5f, -0.5f),
		Vector3(-0.5f, -0.5f, -0.5f),
		Vector3(0.5f, -0.5f, -0.5f),
		Vector3(0.5f, 0.5f, -0.5f),
	};

	Matrix4x4 m(1.0f);
	m[0][1] = 2.0f;
	m(1, 2) = 2.0f;

	vertices[0] = Vector3::Cross(vertices[0], vertices[1]) * 5;
	std::cout << "Cross: " << vertices[0] << std::endl;	
	std::cout << "Dot: " << Vector3::Dot(vertices[0], vertices[1]) << std::endl;
	std::cout << m << std::endl;
	float* values = &vertices[0].x();
	std::cout << values[0] << ", " << values[1] << ", " << values[2] << std::endl;
	 


	static const unsigned short elements[] = {
		
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


	uint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	uint elementBuffer;
	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	revo::graphics::Shader shader;
	shader.simpleLoad("C:/DefaultResources/Shaders/Simple/Simple.vert", "C:/DefaultResources/Shaders/Simple/Simple.frag");

	while (!mWindow->closed()) {
		

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		shader.simpleUse();


		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);		
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		
		// Index buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
		glDrawElements(GL_TRIANGLES, sizeof(elements), GL_UNSIGNED_SHORT, 0);

		glDisableVertexAttribArray(0);

		if (mOnUpdate) mOnUpdate();
		mWindow->update();
	}

	mServices.terminateCoreServices();

	return 0;
}
