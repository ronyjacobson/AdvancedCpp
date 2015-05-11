#include <stdio.h>
#include <iostream>
#include "binIO_t.h"
using namespace std;

binIO_t::binIO_t(){    //CTOR
	// No work to do, call parent constructor.
}

binIO_t::binIO_t(const char* path, const char * mode) : virtIO_t(path, mode) //name CTOR
{ 
	// Verify mode:
	if (mode == NULL || path == NULL){
		throw IOCustomException("NULL argument passed to constructor.\n");
	}

	this->m_path = string(path);
	this->m_mode = string(mode) + 'b';
	errno_t errorCode = fopen_s(&m_file, m_path.c_str(), m_mode.c_str());

	if (m_file == NULL || errorCode != 0){
		m_status = virtIO_t::cant_open_file_e;
		throw IOCustomException("Error while trying to open file.\n");
		return;
	} else {
		m_status == virtIO_t::ok_e;
	}
}

binIO_t::~binIO_t(){			   //DTOR
}

size_t binIO_t::read(void* ptr, size_t size, size_t count)
{
	if (getStatus() == virtIO_t::ok_e)
	{
		size_t n = fread(ptr, size, count, m_file);
		if (feof(m_file))
		{
			m_status = virtIO_t::readErr_e;
			return 0;
		}
		else
			if (ferror(m_file))
			{
				m_status = virtIO_t::bad_access_e;
				return 0;
			}
		return n;
	}
	return 0;
}

size_t binIO_t::write(const void* ptr, size_t size, size_t count)
{
	if (getStatus() == ok_e)
	{
		size_t n = fwrite(ptr, size, count, m_file);
		if (n < count)
		{
			m_status = virtIO_t::writeErr_e;
		}
		else
			return n;
	}
	return 0;
}


virtIO_t& binIO_t::operator<<(const unsigned char& buf){
	return writeTemplate<unsigned char>(buf);
}

virtIO_t& binIO_t::operator<<(const char& buf){
	return writeTemplate<char>(buf);
}

virtIO_t& binIO_t::operator<<(const unsigned short& buf){
	return writeTemplate<unsigned short>(buf);
}

virtIO_t& binIO_t::operator<<(const short& buf){
	return writeTemplate<short>(buf);
}

virtIO_t& binIO_t::operator<<(const unsigned int& buf){
	return writeTemplate<unsigned int>(buf);
}

virtIO_t& binIO_t::operator<<(const int& buf){
	return writeTemplate<int>(buf);
}

virtIO_t& binIO_t::operator<<(const unsigned long& buf){
	return writeTemplate<unsigned long>(buf);
}

virtIO_t& binIO_t::operator<<(const long& buf){
	return writeTemplate<long>(buf);
}

virtIO_t& binIO_t::operator<<(const double& buf){
	return writeTemplate<double>(buf);
}

virtIO_t& binIO_t::operator<<(const float& buf){
	return writeTemplate<float>(buf);
}

virtIO_t& binIO_t::operator>>(char& buf){
	return readTemplate<char>(buf);
}

virtIO_t& binIO_t::operator>>(unsigned short& buf){
	return readTemplate<unsigned short>(buf);
}

virtIO_t& binIO_t::operator>>(short& buf){
	return readTemplate<short>(buf);
}

virtIO_t& binIO_t::operator>>(unsigned int& buf){
	return readTemplate<unsigned int>(buf);
}

virtIO_t& binIO_t::operator>>(int& buf){
	return readTemplate<int>(buf);
}

virtIO_t& binIO_t::operator>>(unsigned long& buf){
	return readTemplate<unsigned long>(buf);
}

virtIO_t& binIO_t::operator>>(long& buf){
	return readTemplate<long>(buf);
}

virtIO_t& binIO_t::operator>>(double& buf){
	return readTemplate<double>(buf);
}

virtIO_t& binIO_t::operator>>(float& buf){
	return readTemplate<float>(buf);
}

virtIO_t& binIO_t::operator>>(unsigned char& buf){
	return readTemplate<unsigned char>(buf);
}