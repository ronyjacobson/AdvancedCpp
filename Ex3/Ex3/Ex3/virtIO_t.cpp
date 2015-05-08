#include "virtIO_t.h"

// CTOR
virtIO_t::virtIO_t() {
	m_file = 0;
	m_path = "";
	m_mode = 0;
	m_status = bad_access_e;
	m_lenght = 0;
}		

// DTOR
virtIO_t::~virtIO_t() {
	fclose(m_file);
}									

// CTOR By path and mode
virtIO_t::virtIO_t(const char * path, const char * mode)
{
	m_path = path;
	m_mode = mode;
	m_file = fopen(m_path, m_mode);

	// Check File
	if (m_file == NULL)
		m_status = cant_open_file_e;
	else
		m_status = ok_e;
}

// Operator ==
bool virtIO_t::operator==(const virtIO_t& virtio) const{
	return (m_path == virtio.m_path) && (m_mode == virtio.m_mode);
}

// Getters
string virtIO_t::getPath() const{
	return m_path;
}

ios_base::openmode virtIO_t::getAccess() const{
	return m_mode;
}

int virtIO_t::getFileLength() const{
	return m_lenght;
}

// IO Operations
ostream virtIO_t::operator,(ostream &out, int& len){

}
istream& virtIO_t::operator,(istream &in, const int& len){

}