#include <iostream>
#include "libwaracle.h"

int unittest_1()
{
	std::string input_filename("unittest/input");
	std::string output_filename("unittest/output");
	int result;

	for(int i = 0; i < 10; i++) {
		/* Generating input & output filenames for the unit test */
		std::string input_str = input_filename + std::to_string(i) + std::string(".txt");
		std::string output_str = output_filename + std::to_string(i) + std::string(".txt");

		/* Calling external function "analyse(...)" from the waracle library */
		result = analyse(input_str.c_str(), output_str.c_str());
		std::cout << input_str << ": " << result << std::endl;
	}

	return 0;
}

int unittest_2()
{
	/* Calling external function "analyse(...)" with invalid arguments */
	std::cout << "unittest/input10 : " << analyse(NULL, "bb") << std::endl;

	return 0;
}

int main() {
	unittest_1();
	unittest_2();
	return 0;
}

