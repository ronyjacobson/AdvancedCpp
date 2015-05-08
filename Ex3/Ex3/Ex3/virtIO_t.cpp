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
virtIO_t::virtIO_t(const char * path, const char * mode)
{
	// Verify mode:
	if (mode == NULL)
	{
		// TODO: Throw custom exception.
	}

	if (path == NULL)
	{
		// TODO: Throw custom exception.
	}

	m_path = string(path);
	m_mode = string(mode);
	m_file = fopen(m_path.c_str(), m_mode.c_str());

	if (m_file == NULL)
	{
		// TODO: Throw custom exception.
		m_status = virtIO_t::cant_open_file_e;
	}
	else
	{
		m_status == virtIO_t::ok_e;
	}
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
