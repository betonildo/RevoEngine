#pragma once
#include <iostream>

namespace revo {
	class Window
	{

	public:

		/// handling events and update
		virtual void Update() = 0;
		virtual bool Closed() = 0;

		/// creating window
		virtual Window* Create(std::string title, int width, int height) = 0;

		///Set window service
		static void SetService(Window* windowService);
		static Window* BuildService(std::string title, int width, int height);
	};
}


