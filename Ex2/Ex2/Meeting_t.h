#pragma once

#include <string>
#include <iostream>

using namespace std;

class Meeting_t
{
public:
	Meeting_t(const float start, const float end, const string& subject);			// CTOR
	~Meeting_t();																	// DTOR
	Meeting_t(const Meeting_t& pr);													// Copy CTOR
	Meeting_t& operator=(const Meeting_t& pr);										// Operator =
	bool operator==(const Meeting_t& pr) const;										// Operator ==

	//Setters and Getters
	void setStartTime(const float start){
		m_start = start;
	};

	float getStartTime() const {
		return m_start;
	};

	void setEndTime(const float end){
		m_end = end;
	};

	float getEndTime() const {
		return m_end;
	};

	void setSubject(string& subject){
		m_subject = subject;
	};

	string getSubject() const {
		return m_subject;
	};

	void print() const {
		cout << getStartTime() << "-" << getEndTime() << " " << getSubject();
	};

	void println() const {
		cout << getStartTime() << "-" << getEndTime() << " " << getSubject() << endl;
	};

	friend ostream& operator<<(ostream& os, const Meeting_t &meeting);

private:
	float				m_start;
	float				m_end;
	string				m_subject;
};