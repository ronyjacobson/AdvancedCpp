
#include "Meeting_t.h"
#include <iostream>
using namespace std;

class DayCalendar_t
{
public:
	DayCalendar_t();										//CTOR
	~DayCalendar_t();										//DTOR

private:
	Meeting_t m_firstMeeting;
	Meeting_t m_lastMeeting;
	int m_numOfMeetings;
	
	const DayCalendar_t& operator=(const DayCalendar_t& pr);	//Operator =
	bool operator==(const DayCalendar_t& pr) const;				//Operator ==
	DayCalendar_t(const DayCalendar_t& pr);						//Copy CTOR

	// Functions
	friend ostream& operator<< (ostream& os, const DayCalendar_t& calendar);

	void incNumOfMeetings() {
		m_numOfMeetings++;
	};

	int insertMeeting(const Meeting_t& meeting);
	int insertMeeting(float endTime, float startTime);

	int deleteMeeting(const Meeting_t& meeting);
	int deleteMeeting(float startTime);
	int deleteMeeting(float endTime);
	
};

