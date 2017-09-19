//
// Create.cpp 
//
#include "stdafx.h"
#include <iostream>
#include <unknwn.h>    // Declare IUnknown.

#include "Create.h"
using std::cout;
using std::endl;

typedef IUnknown* (*CREATEFUNCPTR)() ;

IUnknown* CallCreateInstance(char* name)
{
	// Load dynamic link library into process.
	HINSTANCE hComponent = ::LoadLibraryA(name) ;
	if (hComponent == NULL)
	{
		cout << "CallCreateInstance:\tError: Cannot load component." << endl ;
		return NULL ;
	}

	// Get address for CreateInstance function.
	CREATEFUNCPTR CreateInstance 
		= (CREATEFUNCPTR)::GetProcAddress(hComponent, "CreateInstance") ;
	if (CreateInstance == NULL)
	{
		cout  << "CallCreateInstance:\tError: "
		      << "Cannot find CreateInstance function."
		      << endl ;
		return NULL ;
	}

	return CreateInstance() ;
}
