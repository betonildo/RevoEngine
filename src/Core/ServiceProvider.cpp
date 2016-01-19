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

	Window * ServiceProvider::createWindow(std::string title, int width, int height)
	{
		try {
			return this->mWindowService->create(title, width, height);
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


	void ServiceProvider::initCoreServices()
	{
		for (int i = 0; i < this->mCoreServices.size(); i++) {
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

