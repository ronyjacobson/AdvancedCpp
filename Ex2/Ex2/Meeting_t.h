#pragma once

#include <string>
#include <iostream>

using namespace std;

template <class T>
class Meeting_t
{
public:
	Meeting_t<T>(const float start, const float end, const string& subject);			// CTOR
	virtual ~Meeting_t<T>();															// DTOR
	Meeting_t<T>(const Meeting_t<T>& pr);													// Copy CTOR
	virtual Meeting_t<T>& operator=(const Meeting_t<T>& pr);								// Operator =
	virtual bool operator==(const Meeting_t<T>& pr) const;								// Operator ==
	friend ostream& operator<< <> (ostream& os, const Meeting_t<T> &meeting);
	//Setters and Getters
	void setStartTime(const float start){
		m_start = start;
	};

	virtual float getStartTime() const {
		return m_start;
	};

	virtual void setEndTime(const float end){
		m_end = end;
	};

	virtual float getEndTime() const {
		return m_end;
	};

	virtual void setSubject(string& subject){
		m_subject = subject;
	};

	virtual string getSubject() const {
		return m_subject;
	};

	virtual void print() const {
		cout << getStartTime() << "-" << getEndTime() << " " << getSubject();
	};

	virtual void println() const {
		cout << getStartTime() << "-" << getEndTime() << " " << getSubject() << endl;
	};

private:
	T				m_start;
	T				m_end;
	string				m_subject;
};

template <class T> Meeting_t<T>::Meeting_t<T>(const float start, const float end, const string& subject)				// CTOR by start, end and subject
{
	m_start = start;
	m_end = end;
	m_subject = subject;
}

template <class T> Meeting_t<T>::~Meeting_t<T>()
{
}

template <class T> Meeting_t<T>::Meeting_t<T>(const Meeting_t<T>& pr)													// Copy CTOR
{
	m_start = pr.m_start;
	m_end = pr.m_end;
	m_subject = pr.m_subject;
}


template <class T> Meeting_t<T>& Meeting_t<T>::operator=(const Meeting_t<T>& pr)										// Operator =
{
	if (this == &pr)  // check for self-assignment by comparing the addresses
		return *this;
	m_start = pr.m_start;
	m_end = pr.m_end;
	m_subject = pr.m_subject;
	return *this;
}

template <class T> bool Meeting_t<T>::operator==(const Meeting_t<T>& pr) const										// Operator == that checks for intersections between meetings
{
	bool ret;
	ret = ((m_start <= pr.m_start) && (pr.m_start < m_end));			// Check that the start time of the new meeting is when you have this meeting
	ret = ret || ((m_start < pr.m_end) && (pr.m_end <= m_end));			// Check that the end time of the new meeting is when you have this meeting
	ret = ret || ((pr.m_start <= m_start) && (m_start < pr.m_end));		// Check that the start time of this meeting is when you have the new meeting
	ret = ret || ((pr.m_start < m_end) && (m_end <= pr.m_end));			// Check that the end time of this meeting is when you have the new meeting
	ret = ret || ((m_start == pr.m_start) && (pr.m_end == m_end));		// Check that the start and end times of this meeting is excatly as of the new meeting
	return ret;
}

template <class T> ostream& operator<<(ostream& os, const Meeting_t<T> &meeting)
{
	os << meeting.getStartTime() << "-" << meeting.getEndTime() << " " << meeting.getSubject();
	return os;
}