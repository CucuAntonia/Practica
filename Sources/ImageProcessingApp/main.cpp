#include <iostream>
#include "Algorithms.h"
#include <stdlib.h>
#include <stdbool.h>

// main entry point into the application

int main()
{
	std::cout << "Hello world!" << std::endl;

	if (!Algo::WriteMessage())
		std::cout << "FAILURE: method did not succeded!";

	cv::Mat inImage;
	std::string path = "C:\\Users\\Antonia\\Desktop\\trollhunters.jpg";
	inImage = imread(path, cv::IMREAD_COLOR);

	cv::Mat outImage;

	int option;
	std::cout << "1. Original image" << std::endl;
	std::cout << "2. Averaging algorithm" << std::endl;
	std::cout << "3. Luma/Luminance algorithm" << std::endl;
	std::cout << "4. Desaturation algorithm" << std::endl;
	std::cout << "5. Minimum decomposition algorithm" << std::endl;
	std::cout << "6. Maximum decomposition algorithm" << std::endl;
	std::cout << "7. Custom # of gray shades algorithm" << std::endl;
	std::cout << "8. Single color channel algorithm" << std::endl;
	std::cout << "Enter the option: " << std::endl;
	std::cin >> option;
	std::cout << std::endl;
	

	while (true) {
	system("cls");
	switch (option) {

	case 1:
		cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Original Image", inImage);
		cv::waitKey(0);
		break;
		

	case 2:
		Algo::Averaging(inImage, outImage);
		cv::waitKey(0);
		break;

	case 3:
		Algo::Luminance(inImage, outImage);
		cv::waitKey(0);
		break;

	case 4:
		Algo::Desaturation(inImage, outImage);
		cv::waitKey(0);
		break;

	case 5:
		Algo::Minimum_decomposition(inImage, outImage);
		cv::waitKey(0);
		break;

	case 6:
		Algo::Maximum_decomposition(inImage, outImage);
		cv::waitKey(0);
		break;

	case 7:
		Algo::Custom_gray_shades(inImage, outImage);
		cv::waitKey(0);
		break;

	case 8:
		Algo::Single_color_channel(inImage, outImage);
		cv::waitKey(0);
		break;

	default:
		std::cout << "Insert another value!";
		exit(0);

	}
	}

	return 0;
}