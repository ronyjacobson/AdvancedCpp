#include "Meeting_t.h"
#include <List>
#include "DayCalendar_t.h"
using namespace std;

DayCalendar_t::DayCalendar_t(){} 												//CTOR

DayCalendar_t::~DayCalendar_t(){}												//DTOR

DayCalendar_t::DayCalendar_t(const DayCalendar_t& pr){}							//Copy CTOR

const DayCalendar_t& DayCalendar_t::operator=(const DayCalendar_t& pr){}		//Operator =

bool DayCalendar_t::operator==(const DayCalendar_t& pr) const{}					//Operator ==

void DayCalendar_t::insertMeeting(Meeting_t* const meeting){
	bool canAdd = true;
	for (list<Meeting_t*>::const_iterator ci = m_meetingsList.begin(); ci != m_meetingsList.end(); ++ci)
		if (((Meeting_t&)*ci) == *meeting){
			canAdd = false;
			break;
		}
	if (canAdd){
		m_meetingsList.push_back(meeting);
		m_meetingsList.sort(compare_meetings);
	}
}

void DayCalendar_t::insertMeeting(float startTime, float endTime, string& subject){
	Meeting_t* m = new Meeting_t(startTime, endTime, subject);
	insertMeeting(m);
}

void DayCalendar_t::deleteMeeting(Meeting_t* const meeting){
	m_meetingsList.remove(meeting);
}

void DayCalendar_t::deleteMeeting(float startTime){
	m_meetingsList.remove(searchForMeeting(startTime));
}
Meeting_t* const DayCalendar_t::searchForMeeting(float startTime){
	for (list<Meeting_t*>::const_iterator ci = m_meetingsList.begin(); ci != m_meetingsList.end(); ++ci)
		if (((Meeting_t&)*ci).getStartTime() == startTime)
			return &((Meeting_t&)*ci);
}

ostream& operator<<(ostream& os, const DayCalendar_t &calendar){
	list<Meeting_t*> l = calendar.m_meetingsList;
	for (list<Meeting_t*>::iterator it = l.begin(); it != l.end(); it++) {
		os << *it << '\n';
	}
	os << '\n';
	return os;
}


