#include <iostream>
#include <string>
#include <cstring>
#include "virtIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"

using namespace std;

class Test_t {
public:

	Test_t(){}

	~Test_t()
	{
		if (path_char_pointer != NULL)
		{
			delete path_char_pointer;
		}

		if (mode_char_pointer != NULL)
		{
			delete mode_char_pointer;
		}

		delete aIO;
		delete bIO;
	}

	void getInput() {
		// Get user input
		cout << endl << "Enter file path:" << endl;
		cin >> path;
		path_char_pointer = (char *)malloc(path.size() + 1);
		memcpy(path_char_pointer, path.c_str(), path.size() + 1);
		cout << "Enter io mode:" << endl;
		cin >> mode;
		mode_char_pointer = (char *)malloc(mode.size() + 1);
		memcpy(mode_char_pointer, mode.c_str(), mode.size() + 1);
		cout << "Enter an interger:" << endl;
		cin >> i;
		cout << "Enter a float:" << endl;
		cin >> f;
		cout << "Enter a name (max length is 16 chars):" << endl;
		cin >> name;
		cout << endl;
	}

	void createNewDefaultAsciiIO(){
		aIO = new asciiIO_t();
	}

	void createNewDefaultBinIO(){
		bIO = new binIO_t();
	}

	void createNewAsciiIO(){
		aIO = new asciiIO_t(path_char_pointer, mode_char_pointer);
	}

	void createNewBinIO(){
		bIO = new binIO_t(path_char_pointer, mode_char_pointer);
	}

	void runExampleTest(){

		*aIO << i << ' ' << f;  		// ASCII file ( with blanks )
		*bIO << i << f;					// Binary file
		*bIO << name, nameLength;		// both operator -  ',' and  << for 'void*'
		*bIO >> i >> f;
	}

private:
	virtIO_t * vIO;
	asciiIO_t * aIO;
	binIO_t * bIO;

	string path;
	string mode;

	char * path_char_pointer;
	char * mode_char_pointer;

	int 	i;
	float 	f;
	int		nameLength = 16;
	char 	name[16];
};

//==============================================================

int main() {

	cout << "Your IO Program\n=====================\n\n";

	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - get path and mode" << endl
			<< "2 - create new default ascii IO object" << endl
			<< "3 - create new default binary IO object" << endl
			<< "4 - create new ascii IO object" << endl
			<< "5 - create new binary IO object" << endl
			<< "6 - run test" << endl
			<< "Any other key - quit" << endl;
		cin >> c;
		cout << endl;

		switch (c) {
		case 1:
			test.getInput();
			break;
		case 2:
			test.createNewDefaultAsciiIO();
			break;
		case 3:
			test.createNewDefaultBinIO();
			break;
		case 4:
			test.createNewAsciiIO();
			break;
		case 5:
			test.createNewBinIO();
			break;
		case 6:
			test.runExampleTest();
			break;
		default:
			cont = false;
			break;
		}
	}
	return 0;
}
