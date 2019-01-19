#ifndef WARACLE_LIB_FILEBASE_H
#define WARACLE_LIB_FILEBASE_H

#define FILE_OK		0
#define FILE_ERROR	-1

#include <fstream>
#include <string>
#include <sstream>

/* Deriving FileInput Class from ifstream & streambuf
 * for file access & input capabilities */
class FileInput : public std::ifstream, public std::streambuf
{
public:
	FileInput(const std::string _filename);
	~FileInput();
	int count(int &result);
	int sum(int &result);
	int average(int &result);
};

/* Deriving FileInput Class from ifstream & streambuf
 * for file output capabilities */
class FileOutput : public std::ofstream, public std::streambuf
{
public:
	FileOutput(const std::string _filename);
	~FileOutput();

};

#endif /* WARACLE_LIB_FILEBASE_H*/
