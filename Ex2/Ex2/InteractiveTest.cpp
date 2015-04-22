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

	virtual void insertByDetails() {
		createMeetingFromInput();
		try {
			// Insert meeting
			(*calendar).insertMeeting((*meeting).getStartTime(), (*meeting).getEndTime(), (*meeting).getSubject());
		}
		catch (char const* e) {
			cout << e << endl << endl;
		}
	}

	virtual void insertByObject() {
		createMeetingFromInput();
		try {
			// Insert meeting
			(*calendar).insertMeeting(*meeting);
		}
		catch (char const* e) {
			cout << e << endl << endl;
		}
	}

	virtual void find() {
		createStartTimeFromInput();
		// Find meeting
		try {
			meeting_output = (*calendar).searchForMeeting(start);
			cout << "Found meeting! " << *meeting_output << endl << endl;
		}
		catch (char const* e) {
			cout << e << endl << endl;
		}
	}

	virtual void removeByTime() {
		createStartTimeFromInput();
		// remove meeting
		try {
			(*calendar).deleteMeeting(start);
			cout << "Meeting deleted!" << endl << endl;
		}
		catch (char const* e) {
			cout << e << endl << endl;
		}
	}

	virtual void removeByObject() {
		createMeetingFromInput();
		// remove meeting
		try {
			(*calendar).deleteMeeting(*meeting);
			cout << "Meeting deleted!" << endl << endl;
		}
		catch (char const* e) {
			cout << e << endl << endl;
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
	/*
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

	while (true){}; */

	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - insert (by object)" << endl
			<< "2 - insert (by details)" << endl
			<< "3 - remove (by start time)" << endl
			<< "4 - remove (by object)" << endl
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
			test.removeByTime();
			break;
		case 4:
			test.removeByObject();
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
