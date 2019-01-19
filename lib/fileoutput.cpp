#include "filebase.h"
#include <string>
#include <sstream>

/* Calling ifstream constructor from FileInput constructor for file i/o access */
FileOutput::FileOutput(const std::string _filename) : std::ofstream(_filename) { }

FileOutput::~FileOutput() { }
