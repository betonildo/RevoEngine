// RevoEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RevoEngine.h"


// This is an example of an exported variable
REVOENGINE_API int nRevoEngine=0;

// This is an example of an exported function.
REVOENGINE_API int fnRevoEngine(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see RevoEngine.h for the class definition
CRevoEngine::CRevoEngine()
{
	

    return;
}
