#include <iostream>
#include "virtIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"

using namespace std;

class Test_t {
public:

	Test_t()
	{
		aIO = new assciIO_t();
		bIO = new binIO_t();
	}

	~Test_t()
	{
		if (path != NULL)
		{
			delete path;
		}

		if (mode != NULL)
		{
			delete mode;
		}

		if (aIO != NULL)
		{
			delete aIO;
		}
		
		if (bIO != NULL){
			delete bIO;
		}
	}

	void getInput() {
		// Get user input
		cout << endl << "Enter file path:" << endl;
		cin >> path;
		cout << "Enter io mode:" << endl;
		cin >> mode;
		cout << endl;
	}


	void createStartTimeFromInput() {
		// Get user input
		cout << endl << "Enter start time:" << endl;
		cin >> start;
		cout << endl;
	}

private:
	asciiIO_t aIO;
	bi_t bIO;

	char * path;
	char * mode;
};

//==============================================================

int main() {

	cout << "Your IO Program\n=====================\n\n";

	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - insert (by object)" << endl
			<< "2 - insert (by details)" << endl
			<< "3 - insert with location" << endl
			<< "4 - remove (by start time)" << endl
			<< "5 - search" << endl
			<< "6 - print" << endl
			<< "Any other key - quit" << endl;
		cin >> c;
		cout << endl;

		switch (c) {
		case 1:
			test.insertByObject();
			break;
		case 2:
			test.insertByDetails();
			break;
		case 3:
			test.insertWithLocation();
			break;
		case 4:
			test.removeByTime();
			break;
		case 5:
			test.find();
			break;
		case 6:
			test.print();
			break;
		default:
			cont = false;
			break;
		}
	}
	return 0;
}
