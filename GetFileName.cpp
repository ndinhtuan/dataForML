#include "GetFileName.h"
#include <Windows.h>
#include <fstream>

using std::ofstream;
using std::ifstream;

#include <iostream>

using std::cout;
using std::endl;

#include <sstream>

using std::stringstream;

#include <string>

using std::string;

#include <conio.h>
#include <vector>

using std::vector;

GetFileName::GetFileName()
{
}


GetFileName::~GetFileName()
{
}

void readFilenames(std::vector<string> &fileNames, const string &directory){
	HANDLE dir;
	WIN32_FIND_DATA file_data;

	if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
		return; /*No file found*/

	do{
		const string file_name = file_data.cFileName;
		const string full_file_name = directory + "/" + file_name;
		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

		if (file_name[0] == '.')
			continue;
		if (is_directory)
			continue;
		fileNames.push_back(full_file_name);

	} while (FindNextFile(dir, &file_data));

	FindClose(dir);
}

void GetFileName::getFileNames(const string &folder){
	fileNames.clear();
	readFilenames(fileNames, folder);
	cout << "Get name of file success !" << endl;
	/*for (int i = 0; i < fileNames.size(); i++){
		cout << fileNames[i] << endl;
	}*/
}

void GetFileName::writeNameToFile(const string &file){

	if (fileNames.empty()){
		cout << "Need to get name of file before writing name to file." << endl;
		return;
	}

	ofstream out(file);

	out << fileNames.size() << endl;

	for (size_t i = 0; i < fileNames.size(); i++){
		out << fileNames[i] << std::endl;
	}
}

void GetFileName::renameInFolder(const string &folder){

	if (fileNames.empty()){
		cout << "Need to get name of file before rename file in folder." << endl;
		return;
	}

	stringstream ss;

	for (int i = 0; i < fileNames.size(); i++){
		ss << folder << "/" << i << ".png";
		string newName;
		getline(ss, newName);

		rename(fileNames[i].c_str(), newName.c_str());
		ss.clear();
	}

}

void GetFileName::concatFileInFolder(const string &srcFile, const string &fileConcat){

	if (fileNames.empty()){
		cout << "Need to get name of file before rename file in folder." << endl;
		return;
	}
	ifstream in(fileConcat);
	vector<int> v;

	while (!in.eof()){
		int a;
		in >> a;

		if ((int)in.tellg() != -1){
			v.push_back(a);
		}
	}

	stringstream ss;

	for (int i = 0; i < fileNames.size(); i++){
		ss << srcFile << "/" << i << "_" << v[i] << ".png";
		string newName;
		getline(ss, newName);

		rename(fileNames[i].c_str(), newName.c_str());
		ss.clear();
	}

}