#include "asciiIO_t.h"

using namespace std;

asciiIO_t::asciiIO_t()
{
	// No work to do, call parent constructor.
}

asciiIO_t::asciiIO_t(char * path, char * mode) : virtIO_t(path, mode)
{
	// No work to do, call parent constructor.
}
asciiIO_t::~asciiIO_t()
{
	// No work to do, call parent destructor.
}

size_t asciiIO_t::read(void* ptr, size_t size, size_t count)
{

}

size_t asciiIO_t::write(const void* ptr, size_t size, size_t count)
{

}

virtIO_t& asciiIO_t::operator>>(unsigned char& buf)
{
	return readTemplate<unsigned char>(buf, "%c");
}

virtIO_t& asciiIO_t::operator>>(char& buf)
{
	return readTemplate<char>(buf, "%hhd");
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