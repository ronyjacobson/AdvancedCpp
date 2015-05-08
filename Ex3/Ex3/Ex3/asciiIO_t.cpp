#include "aciiIO_t .h"

using namespace std;

class asciiIO_t : virtIO_t
{
public:
	asciiIO_t() : virtIO_t()
	{
		// Call parent constructor.
	}

	asciiIO_t(string path, ios_base::openmode mode) : virtIO_t(path, mode)
	{
		// Call parent constructor.
	}

private:

};