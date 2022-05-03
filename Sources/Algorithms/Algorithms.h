#pragma once

#ifdef ALGORITHMS_EXPORT
	#define ALGORITHMS_API __declspec(dllexport)
#else
	#define ALGORITHMS_API __declspec(dllimport)
#endif

// a namespace is defined to contain all methods and classes defined in the library, can be renamed at a later time
namespace Algo {

	// method is exported as-is from the library, can be freely called from other projects
	// see also method implementation from source file
	bool ALGORITHMS_API WriteMessage();

}