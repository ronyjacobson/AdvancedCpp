
#include "Meeting_t.h"
#include <iostream>
using namespace std;

class DayCalendar_t
{
public:
	DayCalendar_t();										//CTOR
	~DayCalendar_t();										//DTOR
	DayCalendar_t(const DayCalendar_t& pr);					//Copy CTOR

	Meeting_t& getFirstMeeting() const {
		return *m_firstMeeting;
	}

	Meeting_t& getLastMeeting() const {
		return *m_lastMeeting;
	}

	void setFirstMeeting( Meeting_t* const meeting) {
		m_firstMeeting = meeting;
	}

	void setLastMeeting(Meeting_t* const meeting) {
		m_lastMeeting = meeting;
	}

	const DayCalendar_t& operator=(const DayCalendar_t& pr);	//Operator =
	bool operator==(const DayCalendar_t& pr) const;				//Operator ==
	void insertMeeting(const Meeting_t& meeting);
	void insertMeeting(float endTime, float startTime);
	void deleteMeeting(const Meeting_t& meeting);
	void deleteMeeting(float startTime);
	void deleteMeeting(float endTime);
	friend ostream& operator<< (ostream& os, const DayCalendar_t& calendar);


private:
	Meeting_t* m_firstMeeting;
	Meeting_t* m_lastMeeting;
};

