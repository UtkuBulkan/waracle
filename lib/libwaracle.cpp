#include <sstream>
#include "libwaracle.h"
#include "filebase.h"

/* Calling count, sum & average methods from input class
 * and serialise them into a file via the output class */
int analyse(const char * input, const char * output)
{
	FileOutput *file_output;
	FileInput *file_input;
	int result;

	if ((output == NULL) || (input == NULL)) {
		return FILE_ERROR;
	}

	file_output = new FileOutput(output);
	file_input = new FileInput(input);

	if (file_input->count(result) != FILE_OK) {
		return FILE_ERROR;
	}
	(*file_output) << result << std::endl;

	if (file_input->sum(result) != FILE_OK) {
		return FILE_ERROR;
	}
	(*file_output) << result << std::endl;

	if (file_input->average(result) != FILE_OK) {
		return FILE_ERROR;
	}
	(*file_output) << result << std::endl;

	delete file_output;
	delete file_input;

	return FILE_OK;
}

