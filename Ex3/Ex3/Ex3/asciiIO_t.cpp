#include "asciiIO_t.h"
#include <stdexcept>

using namespace std;

asciiIO_t::asciiIO_t()
{
	// No work to do, call parent constructor.
}

asciiIO_t::asciiIO_t(char * path, char * mode) : virtIO_t(path, mode)
{
	// Verify mode:
	if (mode == NULL || path == NULL)
	{
		throw IOCustomException("NULL argument passed to constructor.\n");
	}

	m_path = string(path);
	m_mode = string(mode);
	errno_t errorCode = fopen_s(&m_file, m_path.c_str(), m_mode.c_str());
	m_op = IOOperation::uninitialized;

	if (m_file == NULL || errorCode != 0)
	{
		m_status = virtIO_t::cant_open_file_e;
		throw IOCustomException("Error while trying to open file.\n");
	}
	else
	{
		m_status == virtIO_t::ok_e;
	}
}

asciiIO_t::~asciiIO_t()
{
	// No work to do, call parent destructor.
}

virtIO_t& asciiIO_t::operator>>(unsigned char& buf)
{
	return readTemplate<unsigned char>(buf, "%c");
}

virtIO_t& asciiIO_t::operator>>(char& buf)
{
	return readTemplate<char>(buf, "%c");
}

virtIO_t& asciiIO_t::operator>>(unsigned short& buf)
{
	return readTemplate<unsigned short>(buf, "%hu");
}

virtIO_t& asciiIO_t::operator>>(short& buf)
{
	return readTemplate<short>(buf, "%hd");
}

virtIO_t& asciiIO_t::operator>>(unsigned int& buf)
{
	return readTemplate<unsigned int>(buf, "%u");
}

virtIO_t& asciiIO_t::operator>>(int& buf)
{
	return readTemplate<int>(buf, "%d");
}

virtIO_t& asciiIO_t::operator>>(unsigned long& buf)
{
	return readTemplate<unsigned long>(buf, "%lu");
}

virtIO_t& asciiIO_t::operator>>(long& buf)
{
	return readTemplate<long>(buf, "%ld");
}

virtIO_t& asciiIO_t::operator>>(float& buf)
{
	return readTemplate<float>(buf, "%f");
}

virtIO_t& asciiIO_t::operator>>(double& buf)
{
	return readTemplate<double>(buf, "%lf");
}

virtIO_t& asciiIO_t::operator<<(const unsigned char& buf)
{
	return writeTemplate<unsigned char>(buf, "%c");
}

virtIO_t& asciiIO_t::operator<<(const char& buf)
{
	return writeTemplate<char>(buf, "%hhd");
}

virtIO_t& asciiIO_t::operator<<(const unsigned short& buf)
{
	return writeTemplate<unsigned short>(buf, "%hu");
}

virtIO_t& asciiIO_t::operator<<(const short& buf)
{
	return writeTemplate<short>(buf, "%hd");
}

virtIO_t& asciiIO_t::operator<<(const unsigned int& buf)
{
	return writeTemplate<unsigned int>(buf, "%u");
}

virtIO_t& asciiIO_t::operator<<(const int& buf)
{
	return writeTemplate<int>(buf, "%d");
}

virtIO_t& asciiIO_t::operator<<(const unsigned long& buf)
{
	return writeTemplate<unsigned long>(buf, "%lu");
}

virtIO_t& asciiIO_t::operator<<(const long& buf)
{
	return writeTemplate<long>(buf, "%ld");
}

virtIO_t& asciiIO_t::operator<<(const float& buf)
{
	return writeTemplate<float>(buf, "%f");
}

virtIO_t& asciiIO_t::operator<<(const double& buf)
{
	return writeTemplate<double>(buf, "%lf");
}

virtIO_t& asciiIO_t::operator<<(void* buffer)
{
	return virtIO_t::operator<<(buffer);
}

virtIO_t& asciiIO_t::operator>>(void* buffer)
{
	return virtIO_t::operator>>(buffer);
}