#pragma once

#ifdef AYM_PLATFORM_WINDOWS
	#ifdef AYM_BUILD_DLL 
		#define AYMARA_API __declspec(dllexport)
	#else
		#define AYMARA_API __declspec(dllimport)
	#endif 
#else
	#error Only Windows Supported!
#endif

#define BIT(x) (1<<x)
