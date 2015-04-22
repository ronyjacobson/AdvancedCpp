#include <iostream>
#include "DayCalendar_t.h"
#include "Meeting_t.h"
#include "MeetingWithLocation_t.h"


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

		// Create meeting
		meeting = new Meeting_t(start, end, subject);
	}

	void createMeetingWithLocationFromInput() {
		// Get user input
		cout << endl << "Enter start time:" << endl;
		cin >> start;
		cout << "Enter end time:" << endl;
		cin >> end;
		cout << "Enter subject:" << endl;
		cin >> subject;
		cout << "Enter location:" << endl;
		cin >> location;
		cout << endl;

		// Create meeting with location
		meetingWithLocation = new MeetingWithLocation_t(start, end, subject, location);
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

	virtual void insertWithLocation() {
		createMeetingWithLocationFromInput();
		try {
			// Insert meeting
			(*calendar).insertMeeting(*meetingWithLocation);
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
	MeetingWithLocation_t* meetingWithLocation;

	float start;
	float end;
	string subject;
	string location;

	Meeting_t* meeting_output;
	MeetingWithLocation_t* meetingWithLocation_output;

};

//==============================================================

int main() {

	cout << "Your Calandar Program\n=====================\n\n";

	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl
			<< "1 - insert (by object)" << endl
			<< "2 - insert (by details)" << endl
			<< "3 - insert with location" << endl
			<< "4 - remove (by start time)" << endl
			<< "5 - remove (by object)" << endl
			<< "6 - search" << endl
			<< "7 - print" << endl
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
			test.removeByObject();
			break;
		case 6:
			test.find();
			break;
		case 7:
			test.print();
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}
