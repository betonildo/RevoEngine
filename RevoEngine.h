// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the REVOENGINE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// REVOENGINE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef REVOENGINE_EXPORTS
#define REVOENGINE_API __declspec(dllexport)
#else
#define REVOENGINE_API __declspec(dllimport)
#endif

// This class is exported from the RevoEngine.dll
class REVOENGINE_API CRevoEngine {
public:
	CRevoEngine(void);
	// TODO: add your methods here.
};

extern REVOENGINE_API int nRevoEngine;

REVOENGINE_API int fnRevoEngine(void);
