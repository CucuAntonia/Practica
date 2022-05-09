#include "Algorithms.h"
#include <iostream>

using namespace std;

namespace Algo {


	bool Averaging(const cv::Mat& inImage, cv::Mat& outImage)
	{
		//Se verifica a fost dat ca parametru o imagine de intrare valida
		if (inImage.rows < 1 ||
			inImage.cols < 1)
			return false;

		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;
		}

		const int noOfChannels = inImage.channels();

		for (int r = 0; r < inImage.rows; r++) 
		{
			for (int c = 0; c < inImage.cols; c++)
			{
				// TO DO: comparativ a se verifica cat dureaza sa accesezi memoria cu at<> vs. alte metode
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(c, r));
				//Se 
				uchar color2 = (color1.val[0] + color1.val[1] + color1.val[2]) / noOfChannels;

				outImage.at<uchar>(cv::Point(c, r)) = color2;
			}
		}
		return true;
	}

	bool Luminance(const cv::Mat& inImage, cv::Mat& outImage)
	{
		if (inImage.rows < 1 ||
			inImage.cols < 1)
			return false;

		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;

		}

		for (int r = 0; r < inImage.rows; r++) 
		{
			for (int c = 0; c < inImage.cols; c++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(c, r));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(c, r));
				//color1.val[2] - Blue
				//color1.val[1] - Green 
				//color1.val[0] - Red
				color2 = (0.11 * color1.val[2] + 0.59 * color1.val[1] + 0.3 * color1.val[0]);

				outImage.at<uchar>(cv::Point(c, r)) = color2.val[0];
			}
		}
		return true;
	}

	bool Desaturation(const cv::Mat& inImage, cv::Mat& outImage)
	{
		if (inImage.rows < 1 ||
			inImage.cols < 1)
			return false;

		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;

		}

		for (int r = 0; r < inImage.rows; r++) 
		{
			for (int c = 0; c < inImage.cols; c++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(c, r));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(c, r));
				color2 = (max({ color1.val[2], color1.val[1], color1.val[0] }) + min({ color1.val[2], color1.val[1], color1.val[0] })) / 2;

				outImage.at<uchar>(cv::Point(c, r)) = color2.val[0];
			}
		}
		return true;
	}

	bool Maximum_decomposition(const cv::Mat& inImage, cv::Mat& outImage)
	{
		if (inImage.rows < 1 ||
			inImage.cols < 1)
			return false;

		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;

		}

		for (int r = 0; r < inImage.rows; r++) 
		{
			for (int c = 0; c < inImage.cols; c++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(c, r));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(c, r));
				color2 = (max({ color1.val[2], color1.val[1], color1.val[0] }));

				outImage.at<uchar>(cv::Point(c, r)) = color2.val[0];
			}
		}
		return true;
	}
	bool Minimum_decomposition(const cv::Mat& inImage, cv::Mat& outImage)
	{
		if (inImage.rows < 1 ||
			inImage.cols < 1)
			return false;

		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;

		}

		for (int r = 0; r < inImage.rows; r++) 
		{
			for (int c = 0; c < inImage.cols; c++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(c, r));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(c, r));
				color2 = (min({ color1.val[2], color1.val[1], color1.val[0] }));

				outImage.at<uchar>(cv::Point(c, r)) = color2.val[0];
			}
		}
		return true;
	}

	bool Single_color_channel(const cv::Mat& inImage, cv::Mat& outImage, ColorChannel colorCh)
	{
		if (inImage.rows < 1 ||
			inImage.cols < 1)
			return false;

		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;

		}

		int colorChIdx = -1;
		switch (colorCh)
		{
		case ColorChannel::Blue:
			colorChIdx = 0;
			break;
		case ColorChannel::Green:
			colorChIdx = 1;
			break;
		case ColorChannel::Red:
			colorChIdx = 2;
			break;
		}

		for (int r = 0; r < inImage.rows; r++)
		{
			for (int c = 0; c < inImage.cols; c++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(c, r));
				uchar color2 = color1.val[colorChIdx];
				outImage.at<uchar>(cv::Point(c, r)) = color2;
			}
		}
		return true;
	}
	bool Custom_gray_shades(const cv::Mat& inImage, cv::Mat& outImage, int conversionFactor)
	{
		if (inImage.rows < 1 ||
			inImage.cols < 1)
			return false;

		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;

		}

		for (int r = 0; r < inImage.rows; r++)
		{
			for (int c = 0; c < inImage.cols; c++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(c, r));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(c, r));
				color2 = (int)(((((color1.val[0] + color1.val[1] + color1.val[2]) / 3) / conversionFactor) + 0.5) * conversionFactor);

				outImage.at<uchar>(cv::Point(c, r)) = color2.val[0];
			}
		}
		return true;
	}

	bool DisplayImage(cv::Mat&outImage, FilterName filterName)
	{
		if (outImage.rows < 1 || outImage.cols < 1)
			return false;
		if (!outImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;

		}
		switch (filterName)
		{
		case FilterName::averaging:
			cv::namedWindow("Averaging", cv::WINDOW_AUTOSIZE);
			cv::imshow("Averaging", outImage);
			cv::waitKey(0);
			break;
		case FilterName::desaturation:
			cv::namedWindow("Desaturation", cv::WINDOW_AUTOSIZE);
			cv::imshow("Desaturation", outImage);
			cv::waitKey(0);
			break;
		case FilterName::maximumDecomposition:
			cv::namedWindow("Maximum_decomposition", cv::WINDOW_AUTOSIZE);
			cv::imshow("Maximum_decomposition", outImage);
			cv::waitKey(0);
			break;
		case FilterName::minimumDecomposition:
			cv::namedWindow("Minimum_decomposition", cv::WINDOW_AUTOSIZE);
			cv::imshow("Minimum_decomposition", outImage);
			cv::waitKey(0);
			break;
		case FilterName::singleColorChannel:
			cv::namedWindow("Single_color_channel", cv::WINDOW_AUTOSIZE);
			cv::imshow("Single_color_channel", outImage);
			cv::waitKey(0);
			break;
		case FilterName::customGrayShades:
			cv::namedWindow("Custom_gray_shades", cv::WINDOW_AUTOSIZE);
			cv::imshow("Custom_gray_shades", outImage);
			cv::waitKey(0);
			break;
		case FilterName::luminance:
			cv::namedWindow("Luminance", cv::WINDOW_AUTOSIZE);
			cv::imshow("Luminance", outImage);
			cv::waitKey(0);
			break;
		}
		return true;
	}
}