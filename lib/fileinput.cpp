#include "filebase.h"
#include <iostream>

/* Calling ifstream constructor from FileInput constructor for file i/o access */
FileInput::FileInput(const std::string _filename)
try : std::ifstream(_filename)
{

}
catch(std::system_error &e)
{
	std::cerr << e.code().message() << std::endl;
}

FileInput::~FileInput() { }

/* Definitions for count, sum & average functions */
int FileInput::count(int &result)
{
	std::string line;
	result = 0;

	/* Check if stream is associated with a file */
	if((*this).is_open() == false) {
		return FILE_ERROR;
	}

	/* Seeking to the begining */
	(*this).clear();
	(*this).seekg(0, std::ios::beg);

	/* Count number of lines */
	while(std::getline(*this, line)) {
		result++;
	}

	return FILE_OK;
}

int FileInput::sum(int &result)
{
	std::string line;
	result = 0;

	/* Check if stream is associated with a file */
	if((*this).is_open() == false) {
		return FILE_ERROR;
	}

	/* Seeking to the begining */
	(*this).clear();
	(*this).seekg(0, std::ios::beg);

	/* Calculate sum */
	while(std::getline(*this, line)) {
		result += std::stoi(line);
	}

	return FILE_OK;
}
int FileInput::average(int &result)
{
	int lines_result, sum_result;

	/* Check if count & sum have been succesfully returned */
	if (count(lines_result) != FILE_OK || sum(sum_result) != FILE_OK) {
		return FILE_ERROR;
	}

	/* if # of lines are positive, calculate average, otherwise
	 * to avoid division by zero return 0. */
	if(lines_result > 0) {
		result = sum_result / lines_result;
	} else {
		result = 0;
	}

	return FILE_OK;
}
