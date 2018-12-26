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

#ifdef AT_ENABLE_ASSERTS	
	#define AT_ASSERT(x, ...) { if(!(x)) { AT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } } 
	#define AT_CORE_ASSERT(x, ...) { if(!(x)) { AT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } } 
#else
	#define AT_ASSERT(x, ...)
	#define AT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)