#include "GetFileName.h"
#include <conio.h>
#include "ConvertData.h"

#define triangle "D:/8_3/triangle_competition/train1/triangle"
#define fileTriangle "train_triangle.txt"
#define non_triangle "D:/8_3/triangle_competition/train1/non-triangle"
#define fileNonTriangle "train_non_triangle.txt"
#define data_triangle "data_triangle.txt"
#define data_non_triangle "data_non_triangle.txt"
#define test "D:/8_3/triangle_competition/test1"

int main(){
	GetFileName ob;

	// concat file test with classifier (y) : fomat nameFile_y
	ob.getFileNames(test);
	ob.concatFileInFolder(test, "C:/Users/9470m/Documents/Visual Studio 2013/Projects/Machine_Learning/Machine_Learning/y.txt");

	// Create training examples
/*
	ob.getFileNames(triangle);
	ob.writeNameToFile(fileTriangle);

	ob.getFileNames(non_triangle);
	ob.writeNameToFile(fileNonTriangle);

	convertData(fileTriangle, data_triangle, 1);
	convertData(fileNonTriangle, data_non_triangle, 0);
*/

	// create testing examples
	/*ob.getFileNames("D:/8_3/triangle_competition/test");
	ob.writeNameToFile("test.txt");

	convertData("test.txt", "data_test.txt");*/
	_getch();
	return 0;
}