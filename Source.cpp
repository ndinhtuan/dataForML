#include "GetFileName.h"
#include <conio.h>
#include "ConvertData.h"

#define triangle "D:/8_3/triangle_competition/train1/triangle"
#define fileTriangle "train_triangle.txt"
#define non_triangle "D:/8_3/triangle_competition/train1/non-triangle"
#define fileNonTriangle "train_non_triangle.txt"
#define data_triangle "data_triangle.txt"
#define data_non_triangle "data_non_triangle.txt"
#define test "D:/8_3/triangle_competition/test"

int main(){
/*
	GetFileName ob;
	ob.getFileNames(triangle);
	ob.writeNameToFile(fileTriangle);
	ob.getFileNames(non_triangle);
	ob.writeNameToFile(fileNonTriangle);

	filterAllFilesInFolder(fileTriangle, data_triangle, 1);
	filterAllFilesInFolder(fileNonTriangle, data_non_triangle, 0);*/
/*
	GetFileName ob;
	
	ob.getFileNames(test);
	ob.writeNameToFile("nameTest.txt");

	filterAllFilesInFolder("nameTest.txt", "test_data.txt");*/

	/*GetFileName ob;
	ob.getFileNames("D:/8_3/triangle_competition/train1/validation_triangle");
	ob.writeNameToFile("validation_triangle.txt");
	ob.getFileNames("D:/8_3/triangle_competition/train1/validation_non_triangle");
	ob.writeNameToFile("validation_non_triangle.txt");

	filterAllFilesInFolder("validation_triangle.txt", "data_validation_triangle.txt", 1);
	filterAllFilesInFolder("validation_non_triangle.txt", "data_validation_non_triangle.txt", 0);*/

	GetFileName ob;
	ob.getFileNames(test);
	ob.concatFileInFolderToFile(test, "C:/Users/9470m/Documents/Visual Studio 2013/Projects/Machine_Learning/Machine_Learning/y.txt", "result_filter.txt");
	_getch();
	return 0;
}