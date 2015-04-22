#include <iostream>
#include "DayCalendar_t.h"
#include "Meeting_t.h"

using namespace std;

class Test_t {
public:

	Test_t(){
		calendar = new DayCalendar_t();
	}

	void createMeetingFromInput() {
		// Get user input
		cout << endl << "Enter start time:" << endl;
		cin >> start;
		cout << "Enter end time:" << endl;
		cin >> end;
		cout << "Enter subject:" << endl;
		cin >> subject;
		cout << endl;

		// Create person
		meeting = new Meeting_t(start, end, subject);
	}

	void createStartTimeFromInput() {
		// Get user input
		cout << endl << "Enter start time:" << endl;
		cin >> start;
		cout << endl;
	}

	virtual void insert() {
		createMeetingFromInput();
		// Insert meeting
		(*calendar).insertMeeting(*meeting);
	}

	virtual void find() {
		createStartTimeFromInput();
		// Find meeting
		try {
		meeting_output = (*calendar).searchForMeeting(start);
			cout << "Found meeting! " << *meeting_output << endl << endl;
		}
		catch (int e) {
			cout << "An error occurred.\n";
		}
	}

	virtual void removeByTime() {
		createStartTimeFromInput();
		// remove meeting
		try {
			(*calendar).deleteMeeting(start);
			cout << "Found meeting! " << *meeting_output << endl << endl;
		}
		catch (int e) {
			cout << "An error occurred.\n";
		}
	}

	virtual void removeByObject() {
		createMeetingFromInput();
		// remove meeting
		try {
			(*calendar).deleteMeeting(*meeting);
			cout << "Found meeting! " << *meeting_output << endl << endl;
		}
		catch (int e) {
			cout << "An error occurred.\n";
		}
	}

	virtual void print() const{
		(*calendar).println();
	}

private:
	DayCalendar_t* calendar;
	Meeting_t* meeting;

	float start;
	float end;
	string subject;

	Meeting_t* meeting_output;

};

//==============================================================

int main() {

	cout << "Your Calandar Program\n=====================\n\n";

	DayCalendar_t * dc = new DayCalendar_t();
	cout << "Calendar created!\n\n";

	Meeting_t * m1 = new Meeting_t(1, 2, "Meeting 1");
	Meeting_t * m2 = new Meeting_t(4, 6, "Meeting 2");
	cout << "The following meetings were created:\n";
	(*m1).println();
	(*m2).print();

	cout << "\n\nAdding meetings to calendar...\n";
	(*dc).insertMeeting(*m1);
	(*dc).insertMeeting(*m2);
	cout << (*dc);

	while (true){};

	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - insert" << endl
			<< "2 - find" << endl
			<< "3 - remove" << endl
			<< "4 - print array" << endl
			<< "5 - get size" << endl
			<< "6 - get capacity" << endl
			<< "7 - remove all" << endl
			<< "8 - remove and delete" << endl
			<< "9 - remove and delete all" << endl
			<< "10 - append" << endl
			<< "11 - prepend" << endl
			<< "12 - get expand value" << endl
			<< "13 - get first" << endl
			<< "14 - get last" << endl
			<< "15 - is empty" << endl
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
		case 12:
			test.expandValue();
			break;
		case 13:
			test.first();
			break;
		case 14:
			test.last();
			break;
		case 15:
			test.empty();
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}
