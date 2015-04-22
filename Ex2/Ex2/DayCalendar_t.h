
#include "Meeting_t.h"
#include <List>
#include <iostream>
using namespace std;

class DayCalendar_t
{
public:
	DayCalendar_t();											//CTOR
	~DayCalendar_t();											//DTOR
	DayCalendar_t(const DayCalendar_t& pr);						//Copy CTOR

	const DayCalendar_t& operator=(const DayCalendar_t& pr);	//Operator =
	void insertMeeting(Meeting_t& const meeting);
	void insertMeeting(float startTime, float endTime, string& subject);
	void insertMeeting(float endTime, float startTime);
	void deleteMeeting(Meeting_t const meeting);
	void deleteMeeting(float startTime);
	Meeting_t* const searchForMeeting(float startTime) const;

	friend ostream& operator<<(ostream& os, const DayCalendar_t& calendar);

	void print() const {
		cout << this;
	};

	void println() const {
		cout << this;
	};

private:
	list<Meeting_t> m_meetingsList;
};


