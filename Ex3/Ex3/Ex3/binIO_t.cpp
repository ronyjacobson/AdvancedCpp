#include <stdio.h>
#include <iostream>
#include "binIO_t.h"
using namespace std;

binIO_t::binIO_t() : virtIO_t(){    //CTOR
}

binIO_t::binIO_t(const char *pathname, const char *mode) : virtIO_t(){ //name CTOR
}

binIO_t::~binIO_t(){			   //DTOR
}

bool binIO_t::setMode(const char *mode){
	char *new_mode = new char[strlen(mode) + 1];
	strcpy(new_mode, mode);
	strcat(new_mode, "b");
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

virtIO_t& binIO_t::operator<<(const char* buf){
	if (buf == 0)
		throw virtIO_t::Input_null_pointer_error();
	size_t temp = strlen(buf);
	if (this->getStatus() == virtIO_t::ok_e)
		if (fwrite(&temp, sizeof(size_t), 1, m_file) < 1)
			m_status = virtIO_t::writeErr_e;
		else{
			if (fwrite(buf, sizeof(char), temp, m_file) < 1){
				m_status = virtIO_t::writeErr_e;
				//remove the size of the string by setting the current position to sizes' position
				fseek(m_file, sizeof(size_t), SEEK_CUR);
			}
		}
		return *this;
}

virtIO_t& binIO_t::operator>>(char* buf)
{
	if (this->getStatus() == virtIO_t::ok_e){
		size_t temp;
		fread(&temp, sizeof(size_t), 1, m_file);
		if (feof(m_file))
			m_status = virtIO_t::read_after_eof_e;
		else
		{
			if (ferror(m_file))
				m_status = virtIO_t::bad_access_e;
			else
			{
				fread(buf, sizeof(char), temp, _file);
				if (feof(m_file))
					m_status = virtIO_t::read_after_eof_e;
				else
					if (ferror(m_file))
						m_status = virtIO_t::bad_access_e;
			}
		}
	}
	return *this;
}