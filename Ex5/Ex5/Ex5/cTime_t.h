#pragma once

class cTime_t {
public:

	// Default CTOR
	cTime_t();

	// Copy CTOR
	cTime_t(const cTime_t& ct);

	// CTOR
	cTime_t(const int hour, const int minutes, const int seconds);

	// DTOR
	~cTime_t();

	// Operator =
	const cTime_t& operator=(const cTime_t& ct);

	// Set Time Function
	// Possibility to set a new time to existing object
	void setTime(const int hour, const int minutes, const int seconds);

	// Print By Format Function
	// format = 1    13:23:12
	// format = 2    1:23:12 PM
	void print(const int format) const;

	// Retrieve Hour Function
	const int getHour() const;

	// Retrieve Minutes Function
	const int getMinutes() const;

	// Retrieve Seconds Function
	const int getSeconds() const;

	// Operator +
	// Possibility to perform addition of one time object to another
	const cTime_t& operator+(const cTime_t& ct);

private:

	// Private Members
	int m_hour;
	int m_minutes;
	int m_seconds;

	// Align To Time Adjustments Function
	void adjustAndSet(const int hour, const int minutes, const int seconds);
};
