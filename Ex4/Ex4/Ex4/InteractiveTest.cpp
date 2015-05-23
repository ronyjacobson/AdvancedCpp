#define TEMPLATE_TEMPLATE_MODE

#include "tContainer_t.h"

#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

#ifndef TEMPLATE_TEMPLATE_MODE
	template<typename T, template <typename, typename> class CT> static void runTest()
#else
	template<typename T, typename CT> static void runTest()
#endif
{
	unsigned int c;
	tContainer_t<T, CT> container;
	T* element;
	const T* containerElement;
	bool cont = true;
	while (cont) {

		cout << "Enter your choice:" << endl
			<< "1 - check if empty" << endl
			<< "2 - show number of elements" << endl
			<< "3 - insert" << endl
			<< "4 - see first" << endl
			<< "5 - see last" << endl
			<< "6 - find" << endl
			<< "7 - remove" << endl
			<< "8 - remove all" << endl
			<< "9 - remove and delete" << endl
			<< "10 - remove and delete all" << endl
			<< "11 - print" << endl
			<< "Any other key - quit" << endl;

		cin >> c;

		switch (c) {
		case 1:
			if (container.isEmpty()) {
				cout << endl << "empty!" << endl << endl;
			} else {
				cout << endl << "not empty!" << endl << endl;
			}
			break;
		case 2:
			cout << endl << "Number Of Elements: " << container.numberOfElements() << endl << endl;
			break;
		case 3:
			element = getUserInput<T>();
			container.insert(element);
			break;
		case 4:
			element = container.first();
			if (element != 0) {
				cout << endl << "First: " << *element << endl << endl;
			} else {
				cout << endl << "empty!" << endl << endl;
			}
			break;
		case 5:
			element = container.last();
			if (element != 0) {
				cout << endl << "Last: " << *element << endl << endl;
			} else {
				cout << endl << "empty!" << endl << endl;
			}
			break;
		case 6:
			element = getUserInput<T>();
			containerElement = container.find(*element);
			if (containerElement != 0) {
				cout << endl << "Element found!" << endl << endl;
			} else {
				cout << endl << "Element not found!" << endl << endl;
			}
			delete element;
			break;
		case 7:
			element = getUserInput<T>();
			containerElement = container.remove(*element);
			if (containerElement != 0) {
				cout << endl << "Element found and removed!" << endl << endl;
			}
			else {
				cout << endl << "Element not found!" << endl << endl;
			}
			delete element;
			delete containerElement;
			break;
		case 8:
			container.removeAll();
			break;
		case 9:
			element = getUserInput<T>();
			container.removeAndDelete(*element);
			delete element;
			break;
		case 10:
			container.removeAndDeleteAll();
			break;
		case 11:
			cout << endl << "Container contains: " << endl << container << endl << endl;
			break;
		default:
			cont = false;
			break;

		}
	}

	container.removeAndDeleteAll();

}

// Get user input
template<class T> static T* getUserInput()
{
	T* element = new T;
	string str;
	cout << endl << "Enter value:" << endl << endl;
	cin >> *element;
	cout << endl;
	while (cin.fail())
	{
		cin.clear();
		cout << endl << "[ERROR] Try again:" << endl << endl;
		cin >> str;
		cin >> *element;
		cout << endl;
	}
	return element;
}

//==============================================================

int main() {

	cout << "Your Template Container Program\n===============================\n\n";

	bool cont = true;			// trigger to stop loop

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - use a vector" << endl
			<< "2 - use a list" << endl
			<< "Any other key - quit" << endl;
		cin >> c;
		cout << endl;

		switch (c) {
		case 1:
			#ifndef TEMPLATE_TEMPLATE_MODE
				runTest<int, vector>();	
			#else
				runTest<int, vector<int*>>();
			#endif
			cont = false;
			break;
		case 2:
			#ifndef TEMPLATE_TEMPLATE_MODE
				runTest<int, list>();
			#else
				runTest<int, list<int*>>();
			#endif
			cont = false;
			break;
		default:
			cont = false;
			break;
		}
	}
	return 0;
}
