#include <iostream>
using namespace std;

class Test_t {
public:
	Test_t(){}
	virtual void	insert()	 { }
	virtual void	find()		 { }
	virtual void	remove()	 { }
	virtual void	print()		 { }
	virtual void	write()		 { }
	void			size() const { }
public:
	int elemCounter;
};

//==============================================================

int main() {

	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - insert" << endl
			<< "2 - find" << endl
			<< "3 - remove" << endl
			<< "4 - print" << endl
			<< "5 - write" << endl
			<< "6 - size" << endl
			<< "Any other key - quit" << endl;
		cin >> c;

		switch (c) {
		case 1:
			test.insert();	// add function parameters
			break;
		case 2:
			test.find();	// add function parameters
			break;
		case 3:
			test.remove();	// add function parameters
			break;
		case 4:
			test.print();	// add function parameters
			break;
		case 5:
			test.write();	// add function parameters
			break;
		case 6:
			test.size();	// add function parameters
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}

