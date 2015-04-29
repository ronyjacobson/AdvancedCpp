
#include "Meeting_t.h"
#include <List>
#include <iostream>
using namespace std;

template <class T>
class DayCalendar_t
{
public:
	DayCalendar_t<T>();											//CTOR
	virtual ~DayCalendar_t<T>();									//DTOR
	
	DayCalendar_t(const DayCalendar_t<T>& pr);						//Copy CTOR

	virtual const DayCalendar_t<T>& operator=(const DayCalendar_t<T>& pr);	//Operator =
	virtual void insertMeeting(Meeting_t<T>* const meeting);
	virtual void insertMeeting(float startTime, float endTime, string& subject);
	virtual void deleteMeeting(Meeting_t<T>* const meeting);
	virtual void deleteMeeting(float startTime);
	virtual Meeting_t<T>* const searchForMeeting(float startTime) const;
	friend ostream& operator<< <>(ostream& os, const DayCalendar_t<T>& calendar);

	virtual void print() const {
		cout << *this;
	};

	virtual void println() const {
		cout << *this << endl;
	};

private:
	list<Meeting_t<T>*> * m_meetingsListPointer;
	list<Meeting_t<T>*> m_meetingsList;
};

template <class T> DayCalendar_t<T>::DayCalendar_t<T>(){ 												//CTOR
	m_meetingsListPointer = new list<Meeting_t<T>*>();
	m_meetingsList = *(m_meetingsListPointer);
}

template <class T> DayCalendar_t<T>::~DayCalendar_t<T>(){												//DTOR
	while (!m_meetingsList.empty()) {
		delete m_meetingsList.front();
		m_meetingsList.pop_front();
	}
	delete(m_meetingsListPointer);
}
template <class T> DayCalendar_t<T>::DayCalendar_t<T>(const DayCalendar_t& pr){}							//Copy CTOR

template <class T> const DayCalendar_t<T>& DayCalendar_t<T>::operator=(const DayCalendar_t<T>& pr){			//Operator =
	if (this == &pr)  // check for self-assignment by comparing the addresses
		return *this;
	m_meetingsList = pr.m_meetingsList;
	return *this;
}

template <class T> void DayCalendar_t<T>::insertMeeting(Meeting_t<T>* const meeting){
	bool canAdd = true;
	for (list<Meeting_t<T>*>::const_iterator ci = m_meetingsList.begin(); ci != m_meetingsList.end(); ++ci)
		if (*((Meeting_t<T>*)*ci) == *meeting){
			canAdd = false;
			break;
		}
	if (canAdd){
		// Add the new meeting
		m_meetingsList.push_back(meeting);
		// Sort all meetings
		m_meetingsList.sort([](const Meeting_t<T>* first, const Meeting_t<T>* second) { return ((*first).getStartTime() < (*second).getStartTime()); });
	}
	else {
		throw "(ERROR) Can\'t add meeting. It intersects with an existing meeting.";
	}
}

template <class T> void DayCalendar_t<T>::insertMeeting(float startTime, float endTime, string& subject){
	if (startTime > endTime){
		throw "(ERROR) Bad meeting times. Start time must be lower than end time.";
	}
	Meeting_t<T>* m = new Meeting_t<T>(startTime, endTime, subject);
	insertMeeting(m);
}

template <class T> void DayCalendar_t<T>::deleteMeeting(Meeting_t<T>* const meeting){
	m_meetingsList.remove(meeting);
}

template <class T> void DayCalendar_t<T>::deleteMeeting(float startTime){
	Meeting_t<T>* m = searchForMeeting(startTime);
	if (m != NULL){
		m_meetingsList.remove(m);
	}
	else {
		throw "(ERROR) Trying to delete a non-existing meeting.";
	}
}

template <class T> Meeting_t<T>* const DayCalendar_t<T>::searchForMeeting(float startTime) const {
	for (list<Meeting_t<T>*>::const_iterator it = m_meetingsList.begin(); it != m_meetingsList.end(); ++it)
	{
		if ((*((Meeting_t<T>*)*it)).getStartTime() == startTime)
			return ((Meeting_t<T>*)*it);
	}
	return NULL;
}

template <class T> ostream& operator<<(ostream& os, const DayCalendar_t<T> &calendar){
	list<Meeting_t<T>*> l = calendar.m_meetingsList;
	for (list<Meeting_t<T>*>::iterator it = l.begin(); it != l.end(); it++) {
		Meeting_t<T> m = *((Meeting_t<T>*)*it);
		os << m;
		if (MeetingWithLocation_t<T> * ml = dynamic_cast<MeetingWithLocation_t<T>*>(*it)) {
			os << ' ' + (*ml).getLocation();
		}
		os << '\n';
	}
	os << '\n';
	return os;
};
