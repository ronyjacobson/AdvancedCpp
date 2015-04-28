#pragma once
#include "Meeting_t.h"

template <class T>
class MeetingWithLocation_t :
	public Meeting_t<T>
{
public:
	MeetingWithLocation_t<T>(const float start, const float end, const string& subject, const string& location);	// CTOR
	virtual ~MeetingWithLocation_t<T>();																					// DTOR

	MeetingWithLocation_t<T>(const Meeting_t& pr);																	// Copy CTOR
	virtual MeetingWithLocation_t<T>& operator=(const Meeting_t& pr);														// Operator =

	void setLocation(string& location){
		m_location = location;
	};

	string getLocation() const {
		return m_location;
	};

	virtual void print() const {
		cout << getStartTime() << "-" << getEndTime() << " " << getSubject() << " " << getLocation();
	};

	virtual void println() const {
		cout << getStartTime() << "-" << getEndTime() << " " << getSubject() << " " << getLocation() << endl;
	};
private:
	string				m_location;
	string				unknowLocation = "Unknow Location";
};

template <class T> MeetingWithLocation_t<T>::MeetingWithLocation_t<T>(const float start, const float end, const string& subject, const string& location) : Meeting_t(start, end, subject)
{
	m_location = location;
}

template <class T> MeetingWithLocation_t<T>::~MeetingWithLocation_t<T>()
{
}

template <class T> MeetingWithLocation_t<T>::MeetingWithLocation_t<T>(const Meeting_t& pr) : Meeting_t(pr.getStartTime(), pr.getEndTime(), pr.getSubject())	// Copy CTOR
{
	if (typeid(&pr) == typeid(MeetingWithLocation_t<T>))
		m_location = ((MeetingWithLocation_t<T>)pr).getLocation();
	else
		m_location = unknowLocation;
}

template <class T> MeetingWithLocation_t<T>& MeetingWithLocation_t<T>::operator=(const Meeting_t& pr)														// Operator =
{
	if (this == &pr)  // check for self-assignment by comparing the addresses
		return *this;
	setStartTime(pr.getStartTime());
	setEndTime(pr.getEndTime());
	setSubject(pr.getSubject());
	if (typeid(&pr) == typeid(MeetingWithLocation_t<T>))
		setLocation(((MeetingWithLocation_t<T>)pr).getLocation());
	else
		setLocation(unknowLocation);
	return *this;
}

template <class T> ostream& operator<<(ostream& os, const MeetingWithLocation_t<T> &meeting){
	os << meeting.getStartTime() << "-" << meeting.getEndTime() << " " << meeting.getSubject() << ", " << meeting.getLocation();
	return os;
}

