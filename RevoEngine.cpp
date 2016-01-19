// RevoEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RevoEngine.h"



// This is the constructor of a class that has been exported.
// see RevoEngine.h for the class definition
CRevoEngine::CRevoEngine()
{
	mServices.addCoreService(new revo::adapter::CoreServiceSDL2());
	mServices.addCoreService(new revo::adapter::CoreServiceGLEW());
	mServices.setWindowService(new revo::adapter::WindowSDL2());	

    return;
}

void CRevoEngine::initSystem()
{
	mServices.initCoreServices();
	mWindow = mServices.createWindow("RevoEngine", 800, 600);

}

void CRevoEngine::handleUpdate(std::function<void()> onUpdate)
{
	mOnUpdate = onUpdate;
}

int CRevoEngine::run()
{

	while (!mWindow->closed()) {
		if (mOnUpdate) mOnUpdate();
		mWindow->update();
	}

	mServices.terminateCoreServices();

	return 0;
}
