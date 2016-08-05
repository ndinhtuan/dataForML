#pragma once
#include <vector>

using std::vector;

#include <string>

using std::string;

class GetFileName
{
public:
	GetFileName();
	~GetFileName();
	void getFileNames(const string &);
	void writeNameToFile(const string &);
	void renameInFolder(const string &);
	void concatFileInFolder(const string &srcFile, const string &fileConcat);
	void concatFileInFolderToFile(const string &srcFile, const string &fileConcat, const string &dstFile);
private:
	vector<string> fileNames;
};

