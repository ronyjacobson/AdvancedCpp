#include "virtIO_t.h"

class binIO_t : virtIO_t{
public:

	binIO_t();			//default CTOR
	binIO_t(const char *pathname, const char* mode); //name CTOR
	~binIO_t();			//DTOR
	virtual bool setMode(const char *mode);

	// operator<< overloads:
	virtual virtIO_t& operator<<(const char& buffer);
	virtual virtIO_t& operator<<(const unsigned char& buffer);
	virtual virtIO_t& operator<<(const short& buffer);
	virtual virtIO_t& operator<<(const unsigned short& buffer);
	virtual virtIO_t& operator<<(const int& buffer) = 0;
	virtual virtIO_t& operator<<(const unsigned int& buffer);
	virtual virtIO_t& operator<<(const long& buffer) = 0;
	virtual virtIO_t& operator<<(const unsigned long& buffer);
	virtual virtIO_t& operator<<(const float& buffer);
	virtual virtIO_t& operator<<(const double& buffer);

	// operator>> overloads:
	using virtIO_t::operator>>;
	virtual virtIO_t& operator>>(char& buffer);
	virtual virtIO_t& operator>>(unsigned char& buffer);
	virtual virtIO_t& operator>>(short& buffer);
	virtual virtIO_t& operator>>(unsigned short& buffer);
	virtual virtIO_t& operator>>(int& buffer);
	virtual virtIO_t& operator>>(unsigned int& buffer);
	virtual virtIO_t& operator>>(long& buffer);
	virtual virtIO_t& operator>>(unsigned long& buffer);
	virtual virtIO_t& operator>>(float& buffer);
	virtual virtIO_t& operator>>(double& buffer);


private:

	// Templated write function for output (operator <<)
	template <class T> binIO_t& writeTemplate(const T& type){
		if (this->good()) {
			if (fwrite(&type, sizeof(T), 1, mFile) < 1) {
				mStatus = virtIO_t::writeErr;
			}
		}
		return *this;
	}

	// Templated read function for input(operator >>)
	template <class T>  binIO_t& readTemplate(T& type){
		if (this->good()) {
			fread(&type, sizeof(T), 1, mFile);
			if (feof(mFile)) {
				mStatus = virtIO_t::readErr_e;
			} else {
				if (ferror(mFile)) {
					mStatus = virtIO_t::bad_access_e;
				}
			}
		}
		return * this;
	}

	binIO_t(const binIO_t& file);				   //copy CTOR
	const binIO_t& operator=(const binIO_t& file); //operator =
	
};