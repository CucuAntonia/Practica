#pragma once
#include <D:\OpenCV\opencv\build\include\opencv2\opencv.hpp>  // TO DO: fix it

#ifdef ALGORITHMS_EXPORT
	#define ALGORITHMS_API __declspec(dllexport)
#else
	#define ALGORITHMS_API __declspec(dllimport)
#endif

// a namespace is defined to contain all methods and classes defined in the library, can be renamed at a later time
namespace Algo {

	// method is exported as-is from the library, can be freely called from other projects
	// see also method implementation from source file
	// TO DO: metodele sa returneze bool sau exceptie
	// nu modifici datele de intrare le faci const

	bool ALGORITHMS_API WriteMessage();
	bool ALGORITHMS_API Averaging(const cv::Mat&inImage, cv::Mat&outImage);
	void ALGORITHMS_API Luminance(cv::Mat& inImage, cv::Mat& outImage);
	void ALGORITHMS_API Desaturation(cv::Mat& inImage, cv::Mat& outImage);
	void ALGORITHMS_API Maximum_decomposition(cv::Mat& inImage, cv::Mat& outImage);
	void ALGORITHMS_API Minimum_decomposition(cv::Mat& inImage, cv::Mat& outImage);

	enum ColorChannel
	{
		Blue = 0,
		Green,
		Red
	};
	void ALGORITHMS_API Single_color_channel(cv::Mat& inImage, cv::Mat& outImage, ColorChannel colorCh = ColorChannel::Green);
	void ALGORITHMS_API Custom_gray_shades(cv::Mat& inImage, cv::Mat& outImage);
	


	

}