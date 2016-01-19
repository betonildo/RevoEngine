#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include "Window.h"
#include "CoreService.h"

namespace revo {

	class ServiceProvider
	{
	private:
		std::vector<CoreService*> mCoreServices;
		Window* mWindowService;

	public:

		///<summary>
		/// Contructor of service provider
		///</summary>
		ServiceProvider();

		///<summary>
		/// Destructor of service provider
		///</summary>
		~ServiceProvider();

		///<summary>
		/// Set a window service to provide a window creation interface.
		///</summary>
		///<param name="windowService">Window service</param>
		void setWindowService(Window* windowService);

		///<summary>
		/// Creates a window based on window service.
		///</summary>
		///<param name="title">Set title of the window</param>
		///<param name="width">Set width of the window</param>
		///<param name="height">Set height of the window</param>
		///<returns>Window pointer</returns>
		Window* createWindow(std::string title, int width, int height);

		///<summary>
		/// Add a core service implemented.
		///</summary>
		///<param name="coreService">A core service implementation</param>
		void addCoreService(CoreService* coreService);

		///<summary>
		/// Initialize all core services on the pool in order.
		///</summary>
		void initCoreServices();

		///<summary>
		/// Terminate all core services on the pool in order.
		///</summary>
		void terminateCoreServices();
	};
}

