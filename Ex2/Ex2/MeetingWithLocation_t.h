#pragma once
#include "Meeting_t.h"

class MeetingWithLocation_t :
	public Meeting_t
{
public:
	MeetingWithLocation_t(const float start, const float end, const string& subject, const string& location);	// CTOR
	~MeetingWithLocation_t();																					// DTOR

	MeetingWithLocation_t(const Meeting_t& pr);																	// Copy CTOR
	MeetingWithLocation_t& operator=(const Meeting_t& pr);														// Operator =

	void setLocation(string& location){
		m_location = location;
	};

	string getLocation() const {
		return m_location;
	};

	void print() const {
		cout << getStartTime() << "-" << getEndTime() << " " << getSubject() << " " << getLocation();
	};

	void println() const {
		cout << getStartTime() << "-" << getEndTime() << " " << getSubject() << " " << getLocation() << endl;
	};

private:
	string				m_location;
};

