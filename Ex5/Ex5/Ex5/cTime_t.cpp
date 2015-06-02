#include "cTime_t.h"

#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

// Default CTOR
cTime_t::cTime_t() {
	
	// Get current time
	time_t timeObject = time(0);
	struct tm* currentTime = localtime(&timeObject);

	// Adjust time
	adjustAndSet(currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);

}

// Copy CTOR
cTime_t::cTime_t(const cTime_t& ct){

	if (this != &ct){
		adjustAndSet(ct.m_hour, ct.m_minutes, ct.m_seconds);
	}

}

// CTOR
cTime_t::cTime_t(const int hour, const int minutes, const int seconds) {
	adjustAndSet(hour, minutes, seconds);
}


// DTOR
cTime_t::~cTime_t(){
	// Does Nothing
}

// Operator =
const cTime_t& cTime_t::operator=(const cTime_t& ct){
	this->m_hour = ct.m_hour;
	this->m_minutes = ct.m_minutes;
	this->m_seconds = ct.m_seconds;
	return *this;
}

// Set Time Function
void cTime_t::setTime(const int hour, const int minutes, const int seconds) {
	adjustAndSet(hour, minutes, seconds);
}

// Print By Format Function
void cTime_t::print(const int format) const {

	if (format == 1){
		// 	format = 1    13:23:12
		cout << setw(2) << setfill('0') << m_hour << ":" 
			<< setw(2)	<< setfill('0') << m_minutes << ":" 
			<< setw(2) << setfill('0') << m_seconds 
			<< endl;
	} else if (format == 2){
		//  format = 2    1:23:12 PM
		cout << setw(2) << setfill('0') << (m_hour <= 12 ? m_hour : m_hour - 12) << ":"
			<< setw(2) << setfill('0') << m_minutes << ":"
			<< setw(2) << setfill('0') << m_seconds << " " << (m_hour < 12 ? "AM" : "PM")
			<< endl;
	} else {
		// Unknown Format
		cout << "[ERROR] Unknow print format." << endl;
	}
}

// Retrieve Hour Function
const int cTime_t::getHour() const {
	return m_hour;
}

// Retrieve Minutes Function
const int cTime_t::getMinutes() const {
	return m_minutes;
}

// Retrieve Seconds Function
const int cTime_t::getSeconds() const {
	return m_seconds;
}

// Operator +
const cTime_t& cTime_t::operator+(const cTime_t& ct) {
	adjustAndSet(this->m_seconds + ct.m_seconds, this->m_minutes + ct.m_minutes, this->m_hour + ct.m_hour);
	return *this;
}

// Align To Time Adjustments Function
void cTime_t::adjustAndSet(const int hour, const int minutes, const int seconds) {
	// Initilize Time Carry
	int c = 0;
	// Set Seconds
	this->m_seconds = seconds;
	// Adjust Seconds
	if (this->m_seconds >= 60) {
		// Set Adjusted Seconds
		c = this->m_seconds / 60;
		this->m_seconds %= 60;
	}
	// Set Minutes
	this->m_minutes = minutes + c;
	c = 0;
	// Adjust Minutes
	if (this->m_minutes >= 60) {
		// Set Adjusted Minutes
		c = this->m_minutes / 60;
		this->m_minutes %= 60;
	}
	// Set Hour
	this->m_hour = hour + c;
	c = 0;
	// Adjust Hour
	if (this->m_hour >= 24) {
		// Set Hour
		c = this->m_hour / 24;
		this->m_hour %= 24;
	}
	// Carry is irrelevant at this point
}
