// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the REVOENGINE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// REVOENGINE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include <functional>
#include <src\Core\ServiceProvider.h>
#include <src\Core\Window.h>

#ifdef REVOENGINE_EXPORTS
#define REVOENGINE_API __declspec(dllexport)
#else
#define REVOENGINE_API __declspec(dllimport)
#endif

// This class is exported from the RevoEngine.dll
class REVOENGINE_API CRevoEngine {
private:
	revo::ServiceProvider mServices;
	revo::Window* mWindow;
	std::function<void()> mOnUpdate;

public:
	///<summary>
	/// Contructor of RevoEngine
	///</summary>
	CRevoEngine(void);
	
	///<summary>
	/// Initialize all system
	///</summary>
	void initSystem();

	///<summary>
	/// Contructor of service provider
	///</summary>
	///<param name="onUpdate">set a function for handling the update process of the window.</param>
	void handleUpdate(std::function<void()> onUpdate);

	///<summary>
	/// Run revo engine and return the exit code.
	///</summary>
	int run();
};
