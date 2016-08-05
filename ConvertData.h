#pragma once
#include <string>

using std::string;

#include <opencv2\imgproc\imgproc.hpp>

using cv::Mat;

// This function is designed for MrLong 's data
//This function convert image data to binary data (text)
// @parameter srcFile is source file include name of image file
// @parameter dstFile is destination file, which is saved binary data from image
// @parameter y is classifier of examples 
void convertData(const string &srcFile, const string &dstFile, int y);
void convertData(const string &srcFile, const string &dstFile);

void filterLaplace(const string &src, Mat &dstImage);
void filterAllFilesInFolder(const string &fileNames, const string &dstFile, int y);
void filterAllFilesInFolder(const string &fileNames, const string &dstFile);

