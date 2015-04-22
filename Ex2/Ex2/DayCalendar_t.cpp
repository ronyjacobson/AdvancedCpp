#include "Meeting_t.h"
#include <List>
#include "DayCalendar_t.h"
using namespace std;

DayCalendar_t::DayCalendar_t(){ 												//CTOR
}

DayCalendar_t::~DayCalendar_t(){												//DTOR
	
}
DayCalendar_t::DayCalendar_t(const DayCalendar_t& pr){}							//Copy CTOR

const DayCalendar_t& DayCalendar_t::operator=(const DayCalendar_t& pr){}		//Operator =

bool DayCalendar_t::operator==(const DayCalendar_t& pr) const{}					//Operator ==

void DayCalendar_t::insertMeeting(const Meeting_t& meeting){}

void DayCalendar_t::insertMeeting(float endTime, float startTime){}

void DayCalendar_t::deleteMeeting(Meeting_t const meeting){
	m_meetingsList.remove(meeting);
}

void DayCalendar_t::deleteMeeting(float startTime){
	m_meetingsList.remove(searchForMeeting(startTime));
}
Meeting_t& const DayCalendar_t::searchForMeeting(float startTime) const {
	for (list<Meeting_t>::const_iterator it = m_meetingsList.begin(); it != m_meetingsList.end(); ++it)
		if (((Meeting_t&)*it).getStartTime() == startTime)
			return ((Meeting_t&)*it);
}

ostream& operator<<(ostream& os, const DayCalendar_t &calendar){
	list<Meeting_t> l = calendar.m_meetingsList;
	for (list<Meeting_t>::iterator it = l.begin(); it != l.end(); it++) {
		os << ((Meeting_t) *it) << '\n';
	}
	os << '\n';
	return os;
}


