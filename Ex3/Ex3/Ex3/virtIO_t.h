#ifndef VIRTIO_T_H
#define VIRTIO_T_H

#include <fstream>
#include <iostream>

using namespace std;

class virtIO_t
{
public:
	virtIO_t();											// CTOR
	virtIO_t(const char * path, const char * mode);		// CTOR By Path And Mode
	~virtIO_t();										// DTOR

	// File Status Enum
	enum fileStatus { ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e };
	
	// IOOperation Enum
	enum IOOperation { read, write, uninitialized };
	
	// Getters
	virtual string getPath() const;
	virtual string getAccess() const;
	virtual long getFileLength() const;

	// Operations and operators
	virtual bool operator==(const virtIO_t& virtio) const;
	virtual virtIO_t& operator,(int len);

	// operator<< overloads
	virtIO_t& operator<<(const void* buffer);
	virtual  virtIO_t& operator<<(const char& buffer) = 0;
	virtual  virtIO_t& operator<<(const unsigned char& buffer) = 0;
	virtual  virtIO_t& operator<<(const short& buffer) = 0;
	virtual  virtIO_t& operator<<(const unsigned short& buffer) = 0;
	virtual  virtIO_t& operator<<(const int& buffer) = 0;
	virtual  virtIO_t& operator<<(const unsigned int& buffer) = 0;
	virtual  virtIO_t& operator<<(const long& buffer) = 0;
	virtual  virtIO_t& operator<<(const unsigned long& buffer) = 0;
	virtual  virtIO_t& operator<<(const float& buffer) = 0;
	virtual  virtIO_t& operator<<(const double& buffer) = 0;

	// operator>> overloads
	virtIO_t& operator>>(void* buffer);
	virtual  virtIO_t& operator>>(char& buffer) = 0;
	virtual  virtIO_t& operator>>(unsigned char& buffer) = 0;
	virtual  virtIO_t& operator>>(short& buffer) = 0;
	virtual  virtIO_t& operator>>(unsigned short& buffer) = 0;
	virtual  virtIO_t& operator>>(int& buffer) = 0;
	virtual  virtIO_t& operator>>(unsigned int& buffer) = 0;
	virtual  virtIO_t& operator>>(long& buffer) = 0;
	virtual  virtIO_t& operator>>(unsigned long& buffer) = 0;
	virtual  virtIO_t& operator>>(float& buffer) = 0;
	virtual  virtIO_t& operator>>(double& buffer) = 0;

	// Status getter and setter
	inline fileStatus getStatus()const{
		return m_status;
	}

	inline void set(fileStatus status){
		m_status = status;
	}



protected:
	FILE *				m_file;
	string				m_path;
	string				m_mode;
	fileStatus			m_status;
	long				m_lenght;
	const void *		m_inputBuffer;
	void *				m_outputBuffer;
	IOOperation			m_op;
	virtual size_t readFromFile(int length);
	virtual size_t writeToFile(int length);
};

// Custom Exception
class IOCustomException
{
public:
	IOCustomException(const string& msg) : m_msg(msg) {}
	~IOCustomException(){};
	string ToString() const
	{
		return m_msg;
	}
private:
	string m_msg;

};
#endif