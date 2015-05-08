#include "aciiIO_t .h"

using namespace std;

class asciiIO_t : virtIO_t
{
public:
	asciiIO_t() : virtIO_t()
	{
		// No work to do, call parent constructor.
	}

	asciiIO_t(string path, ios_base::openmode mode) : virtIO_t(path, mode)
	{
		// No work to do, call parent constructor.
	}
	~asciiIO_t()
	{
		// No work to do, call parent destructor.
	}

	virtual size_t read(void* ptr, size_t size, size_t count)
	{
		if (m_fileStream.good() && m_fileStream.is_open())
		{
			char* buffer = (char*)ptr;
			m_fileStream.read(buffer, count*size);
		}
	}

	virtual size_t write(const void* ptr, size_t size, size_t count)
	{
		if (m_fileStream.good() && m_fileStream.is_open())
		{
			const char* buffer = (char*)ptr;
			m_fileStream.write(buffer, count*size);
		}
	}

private:

};