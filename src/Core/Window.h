#pragma once
#include <iostream>


namespace revo {

	///<summary>
	/// Handle window methods.
	///</summary>
	class Window {
	public:
		///<summary>
		/// Make a update call on window internal functions.
		///</summary>
		virtual void update() = 0;

		///<summary>
		/// Check if a close event was launched by the user.
		///</summary>
		virtual bool closed() = 0;

		///<summary>
		/// Creates a window with title, width and height specified.
		///</summary>
		///<param name='title'>Title of the window</param>
		///<param name='width'>Width of the window</param>
		///<param name='height'>Height of the window</param>
		///<returns>Window pointer</returns>
		virtual Window* create(std::string title, int width, int height) = 0;
	};
}