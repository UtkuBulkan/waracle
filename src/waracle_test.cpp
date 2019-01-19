#include <iostream>
#include "libwaracle.h"

#define POSITIVE_TEST 0
#define NEGATIVE_TEST -1

int unittest_1(int expected)
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
		/* std::cout << input_str << ": " << result << std::endl; */
	}

	return 0;
}

int unittest_2(int expected)
{
	int result = analyse(NULL, "bb");
	/* Calling external function "analyse(...)"
	 * with invalid arguments for negative testing
	 * std::cout << "unittest/input10.txt: " << result << std::endl;
	 */

	return result;
}

int check_unittest(int result, int expected)
{
	int retcode = (result == expected);
	retcode ? std::cout << "PASSED" << std::endl : std::cout << "FAILED" << std::endl;
	return retcode;
}

int main() {
	std::cout << "unittest suite 1 : ";
	check_unittest(unittest_1(POSITIVE_TEST), POSITIVE_TEST);

	std::cout << "unittest suite 2 : ";
	check_unittest(unittest_2(NEGATIVE_TEST), NEGATIVE_TEST);

	return 0;
}

