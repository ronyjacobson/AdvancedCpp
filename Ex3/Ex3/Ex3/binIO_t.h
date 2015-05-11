#ifndef BINIO_T_H
#define BINIO_T_H

#include "virtIO_t.h"

class binIO_t : virtIO_t
{
public:

	binIO_t();			//default CTOR
	binIO_t::binIO_t(const char* path, const char * mode); //name CTOR
	~binIO_t();			//DTOR
	virtual size_t read(void* ptr, size_t size, size_t count);
	virtual size_t write(const void* ptr, size_t size, size_t count);

	// operator<< overloads:
	using virtIO_t::operator<<;
	virtual virtIO_t& operator<<(const char& buffer);
	virtual virtIO_t& operator<<(const unsigned char& buffer);
	virtual virtIO_t& operator<<(const short& buffer);
	virtual virtIO_t& operator<<(const unsigned short& buffer);
	virtual virtIO_t& operator<<(const int& buffer);
	virtual virtIO_t& operator<<(const unsigned int& buffer);
	virtual virtIO_t& operator<<(const long& buffer);
	virtual virtIO_t& operator<<(const unsigned long& buffer);
	virtual virtIO_t& operator<<(const float& buffer);
	virtual virtIO_t& operator<<(const double& buffer);

	// operator>> overloads:
	using virtIO_t::operator>>;
	virtual virtIO_t& operator>>(char& buffer);
	virtual virtIO_t& operator>>(unsigned char& buffer);
	virtual virtIO_t& operator>>(short& buffer);
	virtual virtIO_t& operator>>(unsigned short& buffer);
	virtual virtIO_t& operator>>(int& buffer);
	virtual virtIO_t& operator>>(unsigned int& buffer);
	virtual virtIO_t& operator>>(long& buffer);
	virtual virtIO_t& operator>>(unsigned long& buffer);
	virtual virtIO_t& operator>>(float& buffer);
	virtual virtIO_t& operator>>(double& buffer);

private:

	// Templated write function for output (operator <<)
	template <class T> binIO_t& writeTemplate(const T& type){
		if (this->getStatus() == virtIO_t::ok_e) {
			if (fwrite(&type, sizeof(T), 1, m_file) < 1) {
				m_status = virtIO_t::writeErr_e;
				throw IOCustomException("Error while trying to write to file.\n");
			}
		}
		return *this;
	}

	// Templated read function for input(operator >>)
	template <class T>  binIO_t& readTemplate(T& type){
		if (this->getStatus() == virtIO_t::ok_e) {
			fread(&type, sizeof(T), 1, m_file);
			if (feof(m_file)) {
				m_status = virtIO_t::readErr_e;
			} else {
				if (ferror(m_file)) {
					m_status = virtIO_t::bad_access_e;
					throw IOCustomException("Error while trying to read from file.\n");
				}
			}
		}
		return * this;
	}

	binIO_t(const binIO_t& file);				   //copy CTOR
	const binIO_t& operator=(const binIO_t& file); //operator =
	
};

#endif