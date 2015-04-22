#include "Meeting_t.h"
#include "DayCalendar_t.h"


DayCalendar_t::DayCalendar_t()
{
}



DayCalendar_t::DayCalendar_t(const DayCalendar_t& cal)							// Copy CTOR
{
}


DayCalendar_t::~DayCalendar_t()													//DTOR
{
}

const DayCalendar_t& DayCalendar_t::operator=(const DayCalendar_t& cal)			// Operator =
{
}

bool DayCalendar_t::operator==(const DayCalendar_t& cal)	const				// Operator ==
{
}

void DayCalendar_t::insertMeeting(const Meeting_t& meeting){
};
void DayCalendar_t::insertMeeting(float endTime, float startTime){
};
void DayCalendar_t::deleteMeeting(const Meeting_t& meeting){
};
void DayCalendar_t::deleteMeeting(float startTime){
};
void DayCalendar_t::deleteMeeting(float endTime){
};
