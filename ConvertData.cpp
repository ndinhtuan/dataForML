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