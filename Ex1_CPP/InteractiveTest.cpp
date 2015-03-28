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

	virtual void	insert()	 {
		createPersonFromInput();
		// Insert person
		array->insert(*person);
	}

	virtual void	find()		 { }
	virtual void	remove()	 { }
	virtual void	print()		 { }
	virtual void	write()		 { }
	virtual void	capacity()	 { }
	virtual void	removeAll()	 { }
	virtual void	removeAndDelete()	 { }
	virtual void	removeAndDeleteAll()	 { }
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
			<< "5 - write" << endl
			<< "6 - size" << endl
			<< "7 - capacity" << endl
			<< "8 - remove all" << endl
			<< "9 - remove and delete" << endl
			<< "10 - remove and delete all" << endl
			<< "11 - append" << endl
			<< "12 - prepend" << endl
			<< "Any other key - quit" << endl;
		cin >> c;
		cout << endl;

		

		switch (c) {
		case 1:
			test.insert();
			break;
		case 2:
			test.find();
			// Get user input
			cout << endl << "Enter name:" << endl;
			cin >> name;
			// Find person
			person = (Person_t*) array->find(name);
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
			test.size();
			break;
		case 7:
			cout << "The capacity of the array is " << array->getCapacity() << endl << endl;
			break;
		case 8:
			array->removeAll();
			cout << "All people removed!" << endl << endl;
			break;
		case 9:
			// Get user input
			cout << endl << "Enter name:" << endl;
			cin >> name;
			// Remove person
			array->removeAndDelete(name);
			cout << "Person removed and deleted!" << endl << endl;
			break;
		case 10:
			array->removeAndDeleteAll();
			cout << "All people removed and deleted!" << endl << endl;
			break;
		case 11:
			test.append();
			break;
		case 12:
			test.prepend();
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}

