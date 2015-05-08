#ifndef VIRTIO_T_H
#define VIRTIO_T_H

#include <fstream>
#include <iostream>

using namespace std;

enum FileStatus { ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e };

class virtIO_t
{
public:
	virtIO_t();											// CTOR
	virtIO_t(string path, ios_base::openmode mode);		// Copy CTOR
	~virtIO_t();										// DTOR
	virtual string getPath();
	virtual ios_base::openmode getMode();
	virtual int getFileLength();
	virtual size_t read(void* ptr, size_t size, size_t count);
	virtual size_t write(const void* ptr, size_t size, size_t count);
	friend virtual ostream operator<<(ostream &out, void* buffer);
	friend virtual istream& operator>>(istream &in, const void* buffer);

private:
	fstream m_fileStream;
	ios_base::openmode m_mode;
	unsigned int m_inputOffset;
	unsigned int m_outputOffset;
};


#endif