#include "Meeting_t.h"
#include "DayCalendar_t.h"


DayCalendar_t::DayCalendar_t(){ 												//CTOR

}
DayCalendar_t::~DayCalendar_t(){}												//DTOR
DayCalendar_t::DayCalendar_t(const DayCalendar_t& pr){}							//Copy CTOR
const DayCalendar_t& DayCalendar_t::operator=(const DayCalendar_t& pr){}		//Operator =
bool DayCalendar_t::operator==(const DayCalendar_t& pr) const{}					//Operator ==
void DayCalendar_t::insertMeeting(const Meeting_t& meeting){}
void DayCalendar_t::insertMeeting(float endTime, float startTime){}
void DayCalendar_t::deleteMeeting(const Meeting_t& meeting){}
void DayCalendar_t::deleteMeeting(float startTime){}
void DayCalendar_t::searchForMeeting(float startTime){}

ostream& operator<< (ostream& os, const DayCalendar_t& calendar){
	return os;
}