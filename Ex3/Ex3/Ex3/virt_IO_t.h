#ifndef VIRTIO_T_H
#define VIRTIO_T_H

#include <fstream>
#include <iostream>

using namespace std;

enum FileStatus { ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e };

class virtIO_t
{
public:
	virtIO_t();
	virtIO_t(string path, ios_base::openmode mode);
	~virtIO_t();
	virtual string GetPath();
	virtual ios_base::openmode GetMode();
	friend virtual ostream operator<<(ostream &out, void* buffer);
	friend virtual istream& operator>>(istream &in, const void* buffer);

private:
	fstream m_fileStream;
	ios_base::openmode m_mode;
	unsigned int m_inputOffset;
	unsigned int m_outputOffset;
};


#endif