#include "Algorithms.h"
#include <iostream>

using namespace std;

namespace Algo {

	bool WriteMessage()
	{
		cout << "Hello from library!" << endl;
		return true;
	}

	bool Averaging(const cv::Mat& inImage, cv::Mat& outImage)
	{
		// TO DO: verifici intrarea
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
				uchar color2 = (color1.val[0] + color1.val[1] + color1.val[2]) / noOfChannels;

				outImage.at<uchar>(cv::Point(c, r)) = color2;
			}
		}
		cv::namedWindow("Averaging", cv::WINDOW_AUTOSIZE);
		cv::imshow("Averaging", outImage);
	}

	void Luminance(cv::Mat& inImage, cv::Mat& outImage)
	{
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";

		}

		for (int i = 0; i < inImage.cols; i++) {
			for (int j = 0; j < inImage.rows; j++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(i, j));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(i, j));
				color2 = (0.11 * color1.val[2] + 0.59 * color1.val[1] + 0.3 * color1.val[0]);

				outImage.at<uchar>(cv::Point(i, j)) = color2.val[0];
			}
		}
		cv::namedWindow("Luminance", cv::WINDOW_AUTOSIZE);
		cv::imshow("Luminance", outImage);

	}

	void Desaturation(cv::Mat& inImage, cv::Mat& outImage)
	{
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";

		}

		for (int i = 0; i < inImage.cols; i++) {
			for (int j = 0; j < inImage.rows; j++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(i, j));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(i, j));
				color2 = (max({ color1.val[2], color1.val[1], color1.val[0] }) + min({ color1.val[2], color1.val[1], color1.val[0] })) / 2;

				outImage.at<uchar>(cv::Point(i, j)) = color2.val[0];
			}
		}
		cv::namedWindow("Desaturation", cv::WINDOW_AUTOSIZE);
		cv::imshow("Desaturation", outImage);
	}

	void Maximum_decomposition(cv::Mat& inImage, cv::Mat& outImage)
	{
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";

		}

		for (int i = 0; i < inImage.cols; i++) {
			for (int j = 0; j < inImage.rows; j++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(i, j));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(i, j));
				color2 = (max({ color1.val[2], color1.val[1], color1.val[0] }));

				outImage.at<uchar>(cv::Point(i, j)) = color2.val[0];
			}
		}
		cv::namedWindow("Maximum_decomposition", cv::WINDOW_AUTOSIZE);
		cv::imshow("Maximum_decomposition", outImage);
	}

	void Minimum_decomposition(cv::Mat& inImage, cv::Mat& outImage)
	{
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";

		}

		for (int i = 0; i < inImage.cols; i++) {
			for (int j = 0; j < inImage.rows; j++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(i, j));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(i, j));
				color2 = (min({ color1.val[2], color1.val[1], color1.val[0] }));

				outImage.at<uchar>(cv::Point(i, j)) = color2.val[0];
			}
		}
		cv::namedWindow("Minimum_decomposition", cv::WINDOW_AUTOSIZE);
		cv::imshow("Minimum_decomposition", outImage);
	}

	void Single_color_channel(cv::Mat& inImage, cv::Mat& outImage, ColorChannel colorCh)
	{
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";

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
		cv::namedWindow("Single_color_channel", cv::WINDOW_AUTOSIZE);
		cv::imshow("Single_color_channel", outImage);
	}

	void Custom_gray_shades(cv::Mat& inImage, cv::Mat& outImage)
	{
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		if (!inImage.data)
		{
			std::cout << "Error loading image... \n";

		}

		int conversionfactor;
		cout << "Conversionfactor: "; cin >> conversionfactor;

		for (int i = 0; i < inImage.cols; i++) {
			for (int j = 0; j < inImage.rows; j++)
			{
				cv::Vec3b color1 = inImage.at<cv::Vec3b>(cv::Point(i, j));
				cv::Scalar color2 = outImage.at<uchar>(cv::Point(i, j));
				color2 = (int)(((((color1.val[0] + color1.val[1] + color1.val[2]) / 3) / conversionfactor) + 0.5) * conversionfactor);

				outImage.at<uchar>(cv::Point(i, j)) = color2.val[0];
			}
		}
		cv::namedWindow(" Custom_gray_shades", cv::WINDOW_AUTOSIZE);
		cv::imshow(" Custom_gray_shades", outImage);
	}

}