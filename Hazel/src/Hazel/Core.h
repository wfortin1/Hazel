#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	// When HZ_BUILD_DLL is defined we dllexport the class/function 
	// Otherwise it will be dllimport meaning it is being imported from the DLL
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif


#define BIT(x) (1 << x)