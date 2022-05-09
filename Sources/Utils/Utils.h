#pragma once
#include <opencv2\opencv.hpp>  

#ifdef UTILS_EXPORT
#define UTILS_API __declspec(dllexport)
#else
#define UTILS_API __declspec(dllimport)
#endif

namespace Utils
{
	bool UTILS_API WriteMessage();
}