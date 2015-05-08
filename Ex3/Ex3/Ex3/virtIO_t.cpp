#include "virtIO_t.h"

// CTOR
virtIO_t::virtIO_t() {
	m_path = "./newFile.txt";
	m_mode = std::ios_base::in;
	m_fileStream.open(m_path, m_mode);
}		

// DTOR
virtIO_t::~virtIO_t() {
	m_fileStream.close();
}									

// CTOR By path and mode
virtIO_t::virtIO_t(string path, ios_base::openmode mode)
{
	m_path = path;
	m_mode = mode;
	m_fileStream.open(path, mode);
}

// Operator ==
bool virtIO_t::operator==(const virtIO_t& virtio) const{
	return (m_path == virtio.m_path) && (m_mode == virtio.m_mode);
}