#include "MeetingWithLocation_t.h"


MeetingWithLocation_t::MeetingWithLocation_t(const float start, const float end, const string& subject, const string& location) : Meeting_t(start, end, subject)
{
	m_location = location;
}


MeetingWithLocation_t::~MeetingWithLocation_t()
{
}

MeetingWithLocation_t::MeetingWithLocation_t(const Meeting_t& pr) : Meeting_t(pr.getStartTime(), pr.getEndTime(), pr.getSubject())	// Copy CTOR
{
	if (typeid(&pr) == typeid(MeetingWithLocation_t))
		m_location = ((MeetingWithLocation_t)pr).getLocation();
	else
		m_location = unknowLocation;
}


MeetingWithLocation_t& MeetingWithLocation_t::operator=(const Meeting_t& pr)														// Operator =
{
	if (this == &pr)  // check for self-assignment by comparing the addresses
		return *this;
	setStartTime(pr.getStartTime());
	setEndTime(pr.getEndTime());
	setSubject(pr.getSubject());
	if (typeid(&pr) == typeid(MeetingWithLocation_t))
		setLocation(((MeetingWithLocation_t)pr).getLocation());
	else
		setLocation(unknowLocation);
	return *this;
}

ostream& operator<<(ostream& os, const MeetingWithLocation_t &meeting){
	os << meeting.getStartTime() << "-" << meeting.getEndTime() << " " << meeting.getSubject() << ", " << meeting.getLocation();
	return os;
}
