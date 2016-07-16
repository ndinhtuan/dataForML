#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include <conio.h>

#define fileData "data.txt"

// Function convertToBin serve to save data 
// @parameter matrix is matrix of gray image, which need to convert to binary
// @threshold is thresold, if intensity >= threshold -> 1 else 0.
void covertToBin(Mat &matrix, int threshold = 255);
void saveData(const Mat &matrix, int y, int flag);
void createData();
void createDisturbance(Mat &matrix);

int main(){
	
	int numExamples = 0;
	char c;
	
	while (1){
		system("cls");
		cout << "Example " << ++numExamples << " : " << endl;
		createData();

		cout << "Press c to continue." << endl;
		c = _getch();

		if (c != 'c' && c != 'C'){
			break;
		}
	}

	system("cls");
	cout << "We add " << numExamples << " examples in data." << endl;

	_getch();
	return 0;
}

void covertToBin(Mat &matrix, int threshold){
	for (int i = 0; i < matrix.rows; i++){

		for (int j = 0; j < matrix.cols; j++){

			if (matrix.at<uchar>(i, j) >= threshold){
				matrix.at<uchar>(i, j) = 1;
			}
			else{
				matrix.at<uchar>(i, j) = 0;
			}

		}

	}
}

void saveData(const Mat &matrix, int y, int flag){
	ofstream file; 
	file.open(fileData, std::ios::out | flag);

	if (!file.is_open()){
		cout << "File do not open !" << endl;
		return;
	}

	for (int i = 0; i < matrix.rows; i++){

		for (int j = 0; j < matrix.cols; j++){
			file << (int)(matrix.at<uchar>(i, j)) << " ";
		}

	}

	file << y;
}

void createData(){
	//namedWindow("Test", CV_WINDOW_AUTOSIZE);
	Mat matrix(10, 10, CV_8UC1);
	//threshold(matrix, matrix, 100, 255, THRESH_BINARY);

	//imshow("Test", matrix);
	cvWaitKey(0);
	//destroyWindow("Test");

	Point pointA, pointB, pointC;
	int y;

	cout << "Point A: (x y) ";
	cin >> pointA.x >> pointA.y;

	cout << "Point B : (x, y)";
	cin >> pointB.x >> pointB.y; 

	cout << "Point C : (x, y)";
	cin >> pointC.x >> pointC.y;
	// Input 3 point of triangle
	line(matrix, pointA, pointB, Scalar(255));
	line(matrix, pointA, pointC, Scalar(255));
	line(matrix, pointB, pointC, Scalar(255));

	covertToBin(matrix);
	cout << "Matrix after covert to binary : \n" << matrix << endl;

	createDisturbance(matrix);
	cout << "Matrix after create disturbance : \n" << matrix << endl;

	cout << "Class's name : ";  cin >> y;

	saveData(matrix, y, std::ios::app);
}

void createDisturbance(Mat &matrix){
	int x, y;
	char c;
	cout << "Create disturbance : " << endl;

	while (1){
		cout << "(x y) : ";
		cin >> x >> y;
		matrix.at<uchar>(x, y) = 1;
		cout << "Press c to continue." << endl;
		c = _getch();

		if (c != 'c' && c != 'C'){
			break;
		}
	}
}