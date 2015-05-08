#include <stdio.h>
#include <iostream>
#include "binIO_t.h"
using namespace std;

binIO_t::binIO_t() : virtIO_t(){    //CTOR
}

binIO_t::binIO_t(const char *pathname, const char *mode) : virtIO_t(){ //name CTOR
}

binIO_t::~binIO_t(){			   //DTOR
}

bool binIO_t::setMode(const char *mode){
	char *new_mode = new char[strlen(mode) + 1];
	strcpy(new_mode, mode);
	strcat(new_mode, "b");
}

virtIO_t& binIO_t::operator<<(const unsigned char& buf){
	return writeTemplate<unsigned char>(buf);
}

virtIO_t& binIO_t::operator<<(const char& buf){
	return writeTemplate<char>(buf);
}

virtIO_t& binIO_t::operator<<(const unsigned short& buf){
	return writeTemplate<unsigned short>(buf);
}

virtIO_t& binIO_t::operator<<(const short& buf){
	return writeTemplate<short>(buf);
}

virtIO_t& binIO_t::operator<<(const unsigned int& buf){
	return writeTemplate<unsigned int>(buf);
}

virtIO_t& binIO_t::operator<<(const int& buf){
	return writeTemplate<int>(buf);
}

virtIO_t& binIO_t::operator<<(const unsigned long& buf){
	return writeTemplate<unsigned long>(buf);
}

virtIO_t& binIO_t::operator<<(const long& buf){
	return writeTemplate<long>(buf);
}

virtIO_t& binIO_t::operator<<(const double& buf){
	return writeTemplate<double>(buf);
}

virtIO_t& binIO_t::operator<<(const float& buf){
	return writeTemplate<float>(buf);
}

virtIO_t& binIO_t::operator>>(char& buf){
	return readTemplate<char>(buf);
}

virtIO_t& binIO_t::operator>>(unsigned short& buf){
	return readTemplate<unsigned short>(buf);
}

virtIO_t& binIO_t::operator>>(short& buf){
	return readTemplate<short>(buf);
}

virtIO_t& binIO_t::operator>>(unsigned int& buf){
	return readTemplate<unsigned int>(buf);
}

virtIO_t& binIO_t::operator>>(int& buf){
	return readTemplate<int>(buf);
}

virtIO_t& binIO_t::operator>>(unsigned long& buf){
	return readTemplate<unsigned long>(buf);
}

virtIO_t& binIO_t::operator>>(long& buf){
	return readTemplate<long>(buf);
}

virtIO_t& binIO_t::operator>>(double& buf){
	return readTemplate<double>(buf);
}

virtIO_t& binIO_t::operator>>(float& buf){
	return readTemplate<float>(buf);
}

virtIO_t& binIO_t::operator>>(unsigned char& buf){
	return readTemplate<unsigned char>(buf);
}