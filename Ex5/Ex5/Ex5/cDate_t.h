#pragma once

#include "cTime_t.h"
#include <string.h>

class cDate_t {

public:

	// Default CTOR
	cDate_t();

	// Copy CTOR
	cDate_t(const cDate_t& ct);

	// CTOR
	cDate_t(const int day, const int month, const int year);

	// DTOR
	~cDate_t();

	// Operator =
	const cDate_t& operator=(const cDate_t& ct);

	// Set Date Function
	// Possibility to set a new date to existing object
	void setDate(const int day, const int month, const int year);

	// Print By Format Function
	// format = 1	dd:2, mon:3, year:4 – 22/Jan/2001
	// format = 2	dd:2, mon:2, year:4 – 22/01/2001		European
	// format = 3	mon:2, dd:2, year:4 – 01/22/2001		American
	void print(const int format) const;

	// Retrieve Day Function
	int getDay() const;

	// Retrieve Month Function
	int getMonth() const;

	// Retrieve Year Function
	int getYear() const;

	// Retrieve Day Of Year Function
	int getDayOfYear() const;

	// Retrieve Day Of Month Function
	int getDayOfMonth() const;

	// Check If Leap Year Function
	bool isLeap() const;

	// Retrieve Name Of Day Function
	const char* getDayName() const;

	// Retrieve Name Of Month Function
	const char* getMonthName() const;

	// Operator +
	// A way to connect objects cTime_t and cDate_t in such way, that when functionality 7) of class cTime_t executes (addition),
	// then object of type cDate_t also will be changed (next day, which leads may be to the next month or even a year);
	const cDate_t& cDate_t::operator+(const cTime_t &t);
	
private:

	// Private Members
	int m_day;
	int m_month;
	int m_year;
	int m_dayOfWeek;
	int m_dayOfYear;
	char m_dayName[15];
	char m_monthName[15];

	// A way to connect objects cTime_t and cDate_t 
	cTime_t timeOfDate;

	// Static Members
	static const char * const days[];
	static const char * const months[];

	// Align To Date Adjustments Function
	void adjustAndSet(const int day, const int month, const int year);

	// Check that a time additon to a date won't overflow.
	// A way to connect objects cTime_t and cDate
	bool cDate_t::checkForTimeDateAdjustment(const cTime_t& t);
};