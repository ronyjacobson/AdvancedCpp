#ifndef ASCIIIO_T_H
#define ASCIIIO_T_H

#include "virtIO_t.h"

using namespace std;

class asciiIO_t : virtIO_t
{
public:
	asciiIO_t();
	asciiIO_t(char * path, char * mode);
	~asciiIO_t();
	virtual size_t read(void* ptr, size_t size, size_t count);
	virtual size_t write(const void* ptr, size_t size, size_t count);
	virtual  virtIO_t& operator<<(const unsigned char& buf);

	virtual virtIO_t& operator>>(unsigned char& buf);
	virtual virtIO_t& operator>>(char& buf);
	virtual virtIO_t& operator>>(unsigned short& buf);
	virtual virtIO_t& operator>>(short& buf);
	virtual virtIO_t& operator>>(unsigned int& buf);
	virtual virtIO_t& operator>>(int& buf);
	virtual virtIO_t& operator>>(unsigned long& buf);
	virtual virtIO_t& operator>>(long& buf);
	virtual virtIO_t& operator>>(float& buf);
	virtual virtIO_t& operator>>(double& buf);

	virtual virtIO_t& operator<<(const unsigned char& buf);
	virtual virtIO_t& operator<<(const char& buf);
	virtual virtIO_t& operator<<(const unsigned short& buf);
	virtual virtIO_t& operator<<(const short& buf);
	virtual virtIO_t& operator<<(const unsigned int& buf);
	virtual virtIO_t& operator<<(const int& buf);
	virtual virtIO_t& operator<<(const const unsigned long& buf);
	virtual virtIO_t& operator<<(const long& buf);
	virtual virtIO_t& operator<<(const float& buf);
	virtual virtIO_t& operator<<(const double& buf);
	using virtIO_t::operator<<;
	using virtIO_t::operator >>;

private:
	asciiIO_t(const asciiIO_t& obj); // Copy CTOR
	const asciiIO_t& operator=(const asciiIO_t& obj); // Operator=


	template <class T> asciiIO_t& writeTemplate(const T& buf, const char* format)
	{
		if (getStatus() == virtIO_t::ok_e)
		{
			if (fprintf(m_file, format, buf) < 0)
			{
				m_status = virtIO_t::writeErr_e;
			}
			fprintf(m_file, "%c", ' ');
		}
		return *this;
	}

	template <class T> asciiIO_t& readTemplate(T& buf, const char* format)
	{
		if (getStatus() == virtIO_t::ok_e)
		{
			if (fscanf(m_file, format, &buf) == EOF)
			{
				m_status = virtIO_t::readErr_e;
			}
		}
		return *this;
	}
};


#endif
