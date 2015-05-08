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
	delete m_path;
	delete m_mode;
	fclose(m_file);
}									

// CTOR By path and mode
virtIO_t::virtIO_t(const char * path, const char * mode)
{
	m_path = path;
	m_mode = mode;
	m_file = fopen(m_path, m_mode);

	// Check File Open
	if (m_file == NULL){
		m_status = cant_open_file_e;
	} else {
		m_status = ok_e;
	}
}

// Getters
const char * virtIO_t::getPath() const{
	return m_path;
}

const char * virtIO_t::getAccess() const{
	return m_mode;
}

long virtIO_t::getFileLength() const{
	return m_lenght;
}

// Operations and operators
bool virtIO_t::operator==(const virtIO_t& virtio) const{
	return (m_path == virtio.m_path) && (m_mode == virtio.m_mode);
}
