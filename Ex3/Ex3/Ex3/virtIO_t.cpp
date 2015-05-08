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

// Getters
string virtIO_t::getPath(){
	return m_path;
}

ios_base::openmode virtIO_t::getMode(){
	return m_mode;
}

int virtIO_t::getFileLength(){
	return m_lenght;
}

// IO Operations
size_t virtIO_t::read(void* ptr, size_t size, size_t count){

}
size_t virtIO_t::write(const void* ptr, size_t size, size_t count){

}

// IO Operations
ostream virtIO_t::operator,(ostream &out, int& len){

}
istream& virtIO_t::operator,(istream &in, const int& len){

}