#include "virtIO_t.h"

// CTOR
virtIO_t::virtIO_t() {
	m_file = 0;
	m_path = "";
	m_mode = "";
	m_status = bad_access_e;
	m_lenght = 0;
}		

// DTOR
virtIO_t::~virtIO_t() {
	fclose(m_file);
}									

// CTOR By path and mode
virtIO_t::virtIO_t(const char * path, const char * mode){
}

// Getters
string virtIO_t::getPath() const{
	return m_path;
}

string virtIO_t::getAccess() const{
	return m_mode;
}

long virtIO_t::getFileLength() const{
	return m_lenght;
}

// Operations and operators
bool virtIO_t::operator==(const virtIO_t& virtio) const{
	return (m_path == virtio.m_path) && (m_mode == virtio.m_mode);
}


size_t virtIO_t::readFromFile(int length)
{
	size_t retVal = 0;
	if (m_status == ok_e)
	{
		retVal = fread(m_outputBuffer, sizeof(char), length, m_file);
		if (retVal < length)
		{
			m_status = readErr_e;
		}
	}
	return retVal;
}

size_t virtIO_t::writeToFile(int length)
{
	size_t retVal = 0;
	if (m_status == ok_e)
	{
		retVal = fwrite(m_inputBuffer, sizeof(char), length, m_file);
		if (retVal < length)
		{
			m_status = writeErr_e;
		}
	}
	return retVal;
}


virtIO_t& virtIO_t::operator<<(const void* buffer){
	if (buffer == NULL)
	{
		throw IOCustomException("Null argument passed.\n");
	}
	m_inputBuffer = buffer;
	m_op = IOOperation::write;
	return *this;
}

virtIO_t& virtIO_t::operator>>(void* buffer){
	if (buffer == NULL)
	{
		throw IOCustomException("Null argument passed.\n");
	}
	m_outputBuffer = buffer;
	m_op = IOOperation::read;
	return *this;
}

virtIO_t& virtIO_t::operator,(int length)
{
	if (length < 0)
	{
		throw IOCustomException("Length can't be negative.\n");
	}
	if (m_status != ok_e)
	{
		throw IOCustomException("I/O problem , please check file.\n");
	}

	switch (m_op)
	{
	case IOOperation::read:
		readFromFile(length);
		break;
	case IOOperation::write:
		writeToFile(length);
		break;
	case IOOperation::uninitialized:
		break;
	}
	return *this;
}