#ifndef ASCIIIO_T_H
#define ASCIIIO_T_H

#include "virtIO_t.h"

using namespace std;

class asciiIO_t : virtIO_t
{
public:
	asciiIO_t();
	asciiIO_t(string path, ios_base::openmode mode);
	~asciiIO_t();
	virtual size_t read(void* ptr, size_t size, size_t count);
	virtual size_t write(const void* ptr, size_t size, size_t count);
private:


};


#endif
