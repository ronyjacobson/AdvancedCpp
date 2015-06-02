#include <iostream>
#include <string>
#include <cstring>
#include "cTime_t.h"
#include "cDate_t.h"

using namespace std;

class Test_t {
public:

	Test_t(){}

	~Test_t()
	{
		if (cTime != NULL) delete cTime;
		if (cDate != NULL) delete cDate;
		if (cTimeAdd != NULL) delete cTimeAdd;
	}

	void getTimeInput() {
		// Get user input
		cout << endl << "Enter time properties:" << endl;
		cout << "Enter hour:" << endl;
		cin >> hour;
		cout << "Enter minutes:" << endl;
		cin >> minutes;
		cout << "Enter seconds:" << endl;
		cin >> seconds;
		cout << endl;
	}

	void getDateInput() {
		// Get user input
		cout << endl << "Enter date properties:" << endl;
		cout << "Enter day:" << endl;
		cin >> day;
		cout << "Enter month:" << endl;
		cin >> month;
		cout << "Enter year:" << endl;
		cin >> year;
		cout << endl;
	}

	void getPrintFormatInput() {
		// Get user input
		cout << endl << "Enter print format:" << endl;
		cin >> format;
		cout << endl;
	}

	void createNewTimeObject(){
		getTimeInput();
		cTime = new cTime_t(hour, minutes, seconds);
	}

	void createNewDateObject(){
		getDateInput();
		cDate = new cDate_t(day, month, year);
	}

	void printTimeObject(){
		getPrintFormatInput();
		cTime->print(format);
		cout << endl;
	}

	void printDateObject(){
		getPrintFormatInput();
		cDate->print(format);
		cout << endl;
	}

	void createAnotherTimeObject(){
		getTimeInput();
		cTimeAdd = new cTime_t(hour, minutes, seconds);
	}

	void AddTimeToTime(){
		*cTime = *cTime + *cTimeAdd;
		cTime->print(1);
		cout << endl;
	}

	void AddTimeToDate(){
		*cDate = *cDate + *cTimeAdd;
		cDate->print(1);
		cout << endl;
	}

private:
	cTime_t * cTime = NULL;
	cDate_t * cDate = NULL;
	cTime_t * cTimeAdd = NULL;

	int hour;
	int minutes;
	int seconds;

	int day;
	int month;
	int year;

	int format;
};

//==============================================================

int main() {

	cout << "Your Time-Date Program\n=====================\n\n";

	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - Create new Time object" << endl
			<< "2 - Create new Date object" << endl
			<< "3 - Print Time object by format" << endl
			<< "4 - Print Date object by format" << endl
			<< "5 - Create second Time object" << endl
			<< "6 - Add second Time object with first Time object" << endl
			<< "7 - Add second Time object with Date object" << endl
			<< "Any other key - quit" << endl;
		cin >> c;
		cout << endl;

		switch (c) {
		case 1:
			test.createNewTimeObject();
			break;
		case 2:
			test.createNewDateObject();
			break;
		case 3:
			test.printTimeObject();
			break;
		case 4:
			test.printDateObject();
			break;
		case 5:
			test.createAnotherTimeObject();
			break;
		case 6:
			test.AddTimeToTime();
			break;
		case 7:
			test.AddTimeToDate();
			break;
		default:
			cont = false;
			break;
		}
	}
	return 0;
}
