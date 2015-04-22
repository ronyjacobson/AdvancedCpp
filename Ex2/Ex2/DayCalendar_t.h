
#include "Meeting_t.h"
#include <List>
#include <iostream>
using namespace std;

class DayCalendar_t
{
public:
	DayCalendar_t();											//CTOR
	virtual ~DayCalendar_t();									//DTOR
	
	DayCalendar_t(const DayCalendar_t& pr);						//Copy CTOR

	virtual const DayCalendar_t& operator=(const DayCalendar_t& pr);	//Operator =
	virtual void insertMeeting(Meeting_t& const meeting);
	virtual void insertMeeting(float startTime, float endTime, string& subject);
	virtual void insertMeeting(float endTime, float startTime);
	virtual void deleteMeeting(Meeting_t const meeting);
	virtual void deleteMeeting(float startTime);
	virtual Meeting_t* const searchForMeeting(float startTime) const;

	virtual friend ostream& operator<<(ostream& os, const DayCalendar_t& calendar);

	virtual void print() const {
		cout << this;
	};

	virtual void println() const {
		cout << this;
	};

private:
	list<Meeting_t> m_meetingsList;
};


