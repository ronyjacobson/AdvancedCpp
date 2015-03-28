#include <iostream>
#include "PersonArray_t.h"
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
	int elemCount;
};

//==============================================================

int main() {

	bool cont = true;			// trigger to stop loop

	PersonArray_t* array = new PersonArray_t();

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - insert" << endl
			<< "2 - find" << endl
			<< "3 - remove" << endl
			<< "4 - print" << endl
			<< "5 - write" << endl
			<< "6 - size" << endl
			<< "7 - capacity" << endl
			<< "8 - remove all" << endl
			<< "Any other key - quit" << endl;
		cin >> c;
		cout << endl;

		string name;
		int age;
		Person_t* person;

		switch (c) {
		case 1:
			// Get user input
			cout << endl << "Enter name:" << endl;
			cin >> name;
			cout << "Enter age:" << endl;
			cin >> age;
			cout << endl;
			// Create person
			person = new Person_t(name, age);
			// Insert person
			array->insert(*person);
			break;
		case 2:
			// Get user input
			cout << endl << "Enter name:" << endl;
			cin >> name;
			// Find person
			person = array->find(name);
			cout << "Found person! Name is " << (*person).getName() << " and age is " << (*person).getAge() << endl << endl;
			break;
		case 3:
			// Get user input
			cout << endl << "Enter name:" << endl;
			cin >> name;
			// Remove person
			array->remove(name);
			cout << "Person removed!" << endl << endl;
			break;
		case 4:
			array->print();
			break;
		case 5:
			//array->write();
			break;
		case 6:
			cout << "The size of the array is " << array->getSize() << endl << endl;
			break;
		case 7:
			cout << "The capacity of the array is " << array->getCapacity() << endl << endl;
			break;
		case 8:
			array->removeAll();
			cout << "All people removed!" << endl << endl;
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}

