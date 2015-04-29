#include <iostream>
#include "DayCalendar_t.h"
#include "Meeting_t.h"
#include "MeetingWithLocation_t.h"

typedef float default_type;

using namespace std;

class Test_t {
public:

	Test_t()
	{
		calendar = new DayCalendar_t<default_type>();
	}

	~Test_t()
	{
		if (calendar != NULL)
		{
			delete calendar;
		}
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
		meeting = new Meeting_t<default_type>(start, end, subject);
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
		meetingWithLocation = new MeetingWithLocation_t<default_type>(start, end, subject, location);
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
			(*calendar).insertMeeting(meeting);
		}
		catch (char const* e) {
			cout << e << endl << endl;
		}
	}

	virtual void insertWithLocation() {
		createMeetingWithLocationFromInput();
		try {
			// Insert meeting
			(*calendar).insertMeeting(meetingWithLocation);
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
			if (meeting_output != NULL) {
				cout << "Found meeting!" << *meeting_output << endl << endl;
			} else {
				cout << "No such meeting!" << endl << endl;
			}
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

	virtual void print() const{
		(*calendar).println();
	}

private:
	DayCalendar_t<default_type>* calendar;
	Meeting_t<default_type>* meeting;
	MeetingWithLocation_t<default_type>* meetingWithLocation;

	default_type start;
	default_type end;
	string subject;
	string location;

	Meeting_t<default_type>* meeting_output;
	MeetingWithLocation_t<default_type>* meetingWithLocation_output;

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
