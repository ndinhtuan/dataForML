#include "ConvertData.h"
#include <fstream>

using std::ofstream;
using std::ifstream;

#include <iostream>

using std::endl;
using std::cout;

#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"

using namespace cv;

void convertData(const string &srcFile, const string &dstFile, int y){
	ifstream input(srcFile);
	ofstream output(dstFile);

	int numExamples, countAgain = 0;
	input >> numExamples;
	output << numExamples << " " << 20*20 << endl; // number of examples and features : 20 * 20. size image

	string fileImage;

	while (!input.eof()){
		getline(input, fileImage);

		if ((int)input.tellg() != -1){
			countAgain++;
			Mat img = imread(fileImage, CV_LOAD_IMAGE_GRAYSCALE);

			for (int row = 0; row < img.rows; row++){

				for (int col = 0; col < img.cols; col++){

					int px = img.at<uchar>(row, col);

					if (px == 255){
						output << 1 << " ";
					}
					else{
						output << 0 << " ";
					}

				}

			}

			output << y << endl;
		}

	}

	cout << "Number of examples : " << countAgain << endl;
}

void convertData(const string &srcFile, const string &dstFile){

	ifstream input(srcFile);
	ofstream output(dstFile);

	int numExamples, countAgain = 0;
	input >> numExamples;
	output << numExamples << " " << 20 * 20 << endl; // number of examples and features : 20 * 20. size image

	string fileImage;

	while (!input.eof()){
		getline(input, fileImage);

		if ((int)input.tellg() != -1){
			countAgain++;
			Mat img = imread(fileImage, CV_LOAD_IMAGE_GRAYSCALE);

			for (int row = 0; row < img.rows; row++){

				for (int col = 0; col < img.cols; col++){

					int px = img.at<uchar>(row, col);

					if (px == 255){
						output << 1 << " ";
					}
					else{
						output << 0 << " ";
					}

				}

			}

		}

	}

	cout << "Number of examples : " << countAgain << endl;
}

void filterLaplace(const string &src, Mat &dstImage){
	Mat srcImage = imread(src, CV_LOAD_IMAGE_GRAYSCALE);
	//imshow("src", srcImage);
	Mat kernel = Mat::ones(3, 3, CV_32F);
	kernel.at<uchar>(0, 0) = kernel.at<uchar>(0, 2) = kernel.at<uchar>(2, 0) = kernel.at<uchar>(2, 2) = 0;
	kernel.at<uchar>(1, 1) = -4;
	Point anchor = Point(-1, -1);

	//Mat dstImage;
	filter2D(srcImage, dstImage, -1, kernel, anchor, 0, 4);
	//imwrite(dst, dstImage);
	//imshow("dst", dstImage);
	//cvWaitKey(0);
}

void filterAllFilesInFolder(const string &fileNames, const string &dstFile, int y){
	ifstream in(fileNames);
	ofstream out(dstFile);

	int numExamples;
	in >> numExamples;
	out << numExamples << " " << 400 << endl;

	Mat dstImg;
	string fileImage;

	while (!in.eof()){
		getline(in, fileImage);
		if (fileImage == "") continue;

		if ((int)in.tellg() != -1){
			filterLaplace(fileImage, dstImg);

			for (int row = 0; row < dstImg.rows; row++){

				for (int col = 0; col < dstImg.cols; col++){

					int px = dstImg.at<uchar>(row, col);

					if (px == 255){
						out << 1 << " ";
					}
					else{
						out << 0 << " ";
					}

				}

			}

			out << y << endl;
		}
	}
}

void filterAllFilesInFolder(const string &fileNames, const string &dstFile){

	ifstream in(fileNames);
	ofstream out(dstFile);

	int numExamples;
	in >> numExamples;
	out << numExamples << " " << 400 << endl;

	Mat dstImg;
	string fileImage;

	while (!in.eof()){
		getline(in, fileImage);
		if (fileImage == "") continue;

		if ((int)in.tellg() != -1){
			filterLaplace(fileImage, dstImg);

			for (int row = 0; row < dstImg.rows; row++){

				for (int col = 0; col < dstImg.cols; col++){

					int px = dstImg.at<uchar>(row, col);

					if (px == 255){
						out << 1 << " ";
					}
					else{
						out << 0 << " ";
					}

				}

			}

		}
	}

}