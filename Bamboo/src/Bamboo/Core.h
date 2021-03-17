#pragma once

#ifdef BM_PLATFORM_WINDOWS
	#ifdef BM_BUILD_DLL
		#define BAMBOO_API __declspec(dllexport)
	#else
		#define BAMBOO_API __declspec(dllimport)
	#endif
#else
	#error Bamboo only supports Windows!
#endif