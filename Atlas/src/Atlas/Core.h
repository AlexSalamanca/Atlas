#pragma once

#ifdef AT_PLATFORM_WINDOWS
	#ifdef AT_BUILD_DLL
		#define ATLAS_API __declspec(dllexport)
	#else
		#define ATLAS_API __declspec(dllimport)
	#endif // AT_BUILD_DLL
#else
	#error Atlas only support Windows
#endif // AT_PLATFORM_WINDOWS

#define BIT(x) (1 << x)