#include "cDate_t.h"

#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

// Define Static Members
const char * const cDate_t::days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char * const cDate_t::months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Default CTOR
cDate_t::cDate_t() {

	// Get current date
	time_t timeDate = time(0);
	struct tm* currentDate = localtime(&timeDate);

	// Adjust time
	adjustAndSet(currentDate->tm_mday, currentDate->tm_mon + 1, currentDate->tm_year + 1900);
}

// Copy CTOR
cDate_t::cDate_t(const cDate_t& ct){

	if (this != &ct){
		adjustAndSet(ct.m_day, ct.m_month, ct.m_year);
	}
	
}

// CTOR
cDate_t::cDate_t(const int day, const int month, const int year) {
	adjustAndSet(day, month, year);
}

// DTOR
cDate_t::~cDate_t(){
	// Does Nothing
}

// Operator =
const cDate_t& cDate_t::operator = (const cDate_t& ct){

	this->m_day = ct.m_day;
	this->m_month = ct.m_month;
	this->m_year = ct.m_year;
	this->m_dayOfYear = ct.m_dayOfYear;
	strcpy(this->m_dayName, ct.m_dayName);
	strcpy(this->m_monthName, ct.m_monthName);
	return *this;
}

// Set Date Function
void cDate_t::setDate(const int day, const int month, const int year) {
	adjustAndSet(day, month, year);
}

// Print By Format Function
void cDate_t::print(const int format) const {
	if (format == 1){
		// format = 1	dd:2, mon:3, year:4 – 22/Jan/2001
		cout << setw(2) << setfill('0') << m_day << "/"
			<< m_monthName << "/"
			<< m_year << endl;
	}
	else if (format == 2){
		// format = 2	dd:2, mon:2, year:4 – 22/01/2001		European
		cout << setw(2) << setfill('0') << m_day << "/"
			<< setw(2) << setfill('0') << m_month << "/"
			<< m_year << endl;
	} else if (format == 3){
		// format = 3	mon:2, dd:2, year:4 – 01/22/2001		American
		cout << setw(2) << setfill('0') << m_month << "/"
			<< setw(2) << setfill('0') << m_day << "/"
			<< m_year << endl;
	} else {
		// Unknown Format
		cout << "[ERROR] Unknow print format." << endl;
	}
}

// Retrieve Day Function
int cDate_t::getDay() const {
	return m_dayOfWeek;
}
// Retrieve Month Function
int cDate_t::getMonth() const {
	return m_month;
}
// Retrieve Year Function
int cDate_t::getYear() const {
	return m_year;
}

// Retrieve Day Of Year Function
int cDate_t::getDayOfYear() const {
	return m_dayOfYear;
}
// Retrieve Day Of Month Function
int cDate_t::getDayOfMonth() const {
	return m_day;
}

// Check If Leap Year Function
bool cDate_t::isLeap() const {
	return (m_year % 4 == 0 && m_year % 400 == 0);
}

// Retrieve Name Of Day Function
const char* cDate_t::getDayName() const {
	return m_dayName;
}
// Retrieve Name Of Month Function
const char* cDate_t::getMonthName() const {
	return m_monthName;
}

// Operator +
const cDate_t& cDate_t::operator+(const cTime_t &t){
	// Check if time addition will 
	if (checkForTimeDateAdjustment(t)){
		// Set new date
		setDate(getDayOfMonth() + 1, getMonth(), getYear());
	}
	return *this;
}

// Align To Date Adjustments Function
void cDate_t::adjustAndSet(const int day, const int month, const int year) {
	// Create time object
	time_t timeObject = time(0);
	struct tm* timeLocal = localtime(&timeObject);
	// Adjust Date
	timeLocal->tm_year = year - 1900;
	timeLocal->tm_mon = month - 1;
	timeLocal->tm_mday = day;
	mktime(timeLocal);
	// Set Date Properties
	// Set Day
	this->m_day = timeLocal->tm_mday;
	// Set Month
	this->m_month = timeLocal->tm_mon + 1;
	// Set Year
	this->m_year = timeLocal->tm_year + 1900;
	// Set Day Of Week
	this->m_dayOfWeek = timeLocal->tm_wday + 1;
	// Set Day Of Year
	this->m_dayOfYear = timeLocal->tm_yday;
	// Set Day Name
	strcpy(this->m_dayName, days[timeLocal->tm_wday]);
	// Set Month Name
	strcpy(this->m_monthName, months[this->m_month - 1]);
}

bool cDate_t::checkForTimeDateAdjustment(const cTime_t& t) {
	// Add times and set new time
	this->timeOfDate = this->timeOfDate + t;
	// Check Hour
	if (t.getHour() > this->timeOfDate.getHour()){
		return true;
	} else if (t.getHour() < this->timeOfDate.getHour()){
		return false;
	} else { // ==
		// Check Minutes
		if (t.getMinutes() > this->timeOfDate.getMinutes()) {
			return true;
		} else if (t.getMinutes() < this->timeOfDate.getMinutes()){
			return false;
		} else { // ==
			// Check Seconds
			if (t.getSeconds() > this->timeOfDate.getSeconds()){
				return true;
			}
			else if (t.getSeconds() < this->timeOfDate.getSeconds()){
				return false;
			} else { // ==
				return false;
			}
		}
	}
	return false;
}
