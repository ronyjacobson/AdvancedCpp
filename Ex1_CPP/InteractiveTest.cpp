#include <iostream>
#include "PersonArray_t.h"
using namespace std;

class Test_t {
public:

	Test_t(){
		array = new PersonArray_t();
	}

	void createPersonFromInput() {
		// Get user input
		cout << endl << "Enter name:" << endl;
		cin >> name;
		cout << "Enter age:" << endl;
		cin >> age;
		cout << endl;

		// Create person
		person = new Person_t(name, age);
	}

	void createNameFromInput() {
		// Get user input
		cout << endl << "Enter name:" << endl;
		cin >> name;
		cout << endl;
	}

	virtual void	insert()	 {
		createPersonFromInput();
		// Insert person
		array->insert(*person);
	}

	virtual void	find()		 {
		createNameFromInput();
		// Find person
		person_output = array->find(name);
		cout << "Found person! Name is " << (*person_output).getName() << " and age is " << (*person_output).getAge() << endl << endl;
	}

	virtual void	remove()	 { 
		createNameFromInput();
		array->remove(name);
		cout << "Person removed!" << endl << endl;
	}

	virtual void	print()		 { 
		array->print();
	}

	virtual void	capacity()	 { 
		cout << "The capacity of the array is " << array->getCapacity() << endl << endl;
	}

	virtual void	removeAll()	 {
		array->removeAll();
		cout << "All people removed!" << endl << endl;
	}

	virtual void	removeAndDelete()	 { 
		createNameFromInput();
		// Remove person
		array->remove(name);
		cout << "Person removed and deleted!" << endl << endl;
	}

	virtual void	removeAndDeleteAll()	 { 
		array->removeAndDeleteAll();
		cout << "All people removed and deleted!" << endl << endl;
	}

	virtual int	append()	 {
		int i;
		createPersonFromInput();
		cout << "Enter index:" << endl;
		cin >> i;
		cout << endl;
		// Insert person
		return array->append(i, *person);
	}

	virtual int	prepend()	 {
		int i;
		createPersonFromInput();
		cout << "Enter index:" << endl;
		cin >> i;
		cout << endl;
		// Insert person
		return array->prepend(i, *person);
	}

	void size() const {
		cout << "The size of the array is " << array->getSize() << endl << endl;
	}

private:
	PersonArray_t* array;
	string name;
	int age;
	Person_t* person;
	const Person_t* person_output;
	int elemCount;
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
			<< "5 - size" << endl
			<< "6 - capacity" << endl
			<< "7 - remove all" << endl
			<< "8 - remove and delete" << endl
			<< "9 - remove and delete all" << endl
			<< "10 - append" << endl
			<< "11 - prepend" << endl
			<< "Any other key - quit" << endl;
		cin >> c;
		cout << endl;

		

		switch (c) {
		case 1:
			test.insert();
			break;
		case 2:
			test.find();
			break;
		case 3:
			test.remove();
			break;
		case 4:
			test.print();
			break;
		case 5:
			test.size();
			break;
		case 6:
			test.capacity();
			break;
		case 7:
			test.removeAll();
			break;
		case 8:
			test.removeAndDelete();
			break;
		case 9:
			test.removeAndDeleteAll();
			break;
		case 10:
			test.append();
			break;
		case 11:
			test.prepend();
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}

