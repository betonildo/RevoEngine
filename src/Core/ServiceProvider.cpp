#include "stdafx.h"
#include "ServiceProvider.h"

namespace revo {

	ServiceProvider::ServiceProvider()
	{
		this->mWindowService = NULL;
	}


	ServiceProvider::~ServiceProvider()
	{
	}

	void ServiceProvider::setWindowService(Window * windowService)
	{
		this->mWindowService = windowService;
	}

	Window * ServiceProvider::createWindow(std::string title, int width, int height, int flags)
	{
		try {
			return this->mWindowService->create(title, width, height, flags);
		}
		catch (std::exception ex) {
			std::cerr << "Window service is NULL yet." << std::endl;
			std::cerr << "ERROR: " << ex.what() << std::endl;
		}

		return nullptr;
	}
	void ServiceProvider::addCoreService(CoreService * coreService)
	{
		// not nulll
		if (coreService) {
			this->mCoreServices.push_back(coreService);
		}
	}


	void ServiceProvider::initCoreService(CoreService * coreService)
	{
		// not nulll
		if (coreService) {
			this->mCoreServices.push_back(coreService);
			if (!coreService->hasInitialized())
				coreService->initialize();
		}
	}

	void ServiceProvider::initCoreServices()
	{
		for (int i = 0; i < this->mCoreServices.size(); i++) {
			if(!this->mCoreServices[i]->hasInitialized())
				this->mCoreServices[i]->initialize();
		}
	}

	void ServiceProvider::terminateCoreServices()
	{
		for (int i = 0; i < this->mCoreServices.size(); i++) {
			this->mCoreServices[i]->terminate();
		}
	}

}

