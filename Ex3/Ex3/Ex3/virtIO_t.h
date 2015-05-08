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
	virtIO_t(string path, ios_base::openmode mode);		// CTOR By Path And Mode
	~virtIO_t();										// DTOR
	virtual string getPath();
	virtual ios_base::openmode getMode();
	virtual int getFileLength();
	virtual size_t read(void* ptr, size_t size, size_t count);
	virtual size_t write(const void* ptr, size_t size, size_t count);
	virtual bool operator==(const virtIO_t& virtio) const;
	friend virtual ostream operator,(ostream &out, int& len);
	friend virtual istream& operator,(istream &in, const int& len);
	
	// operator<< overloads:
	friend virtual ostream operator<<(ostream &out, void* buffer);
	friend virtual ostream operator<<(ostream &out, char input);
	friend virtual ostream operator<<(ostream &out, unsigned char input);
	friend virtual ostream operator<<(ostream &out, short input);
	friend virtual ostream operator<<(ostream &out, unsigned short input);
	friend virtual ostream operator<<(ostream &out, int input);
	friend virtual ostream operator<<(ostream &out, unsigned int input);
	friend virtual ostream operator<<(ostream &out, long input);
	friend virtual ostream operator<<(ostream &out, unsigned long input);
	friend virtual ostream operator<<(ostream &out, float input);
	friend virtual ostream operator<<(ostream &out, double input);
	// operator>> overloads:
	friend virtual istream& operator>>(istream &in, const void* buffer);
	friend virtual istream& operator>>(istream &in, char input);
	friend virtual istream& operator>>(istream &in, unsigned char input);
	friend virtual istream& operator>>(istream &in, short input);
	friend virtual istream& operator>>(istream &in, unsigned short input);
	friend virtual istream& operator>>(istream &in, int input);
	friend virtual istream& operator>>(istream &in, unsigned int input);
	friend virtual istream& operator>>(istream &in, long input);
	friend virtual istream& operator>>(istream &in, unsigned long input);
	friend virtual istream& operator>>(istream &in, float input);
	friend virtual istream& operator>>(istream &in, double input);

private:
	fstream				m_fileStream;
	string				m_path;
	ios_base::openmode	m_mode;
	unsigned int		m_inputOffset;
	unsigned int		m_outputOffset;
	int					m_lenght;
};

#endif