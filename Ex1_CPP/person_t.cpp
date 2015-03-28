#include "Person_t.h"

size_t Person_t::m_globID = 0;

Person_t::Person_t() : m_id(m_globID++) {}					// CTOR

Person_t::~Person_t() {										// DTOR
}					

Person_t::Person_t(string& name, int age) :					// CTOR by name and age
m_id(m_globID++)
{
	m_name = name;
	m_age = age;
}


Person_t::Person_t(const Person_t& pr) :					// Copy CTOR
m_id(m_globID++)
{
	m_name = pr.m_name;
	m_age = pr.m_age;
}


Person_t& Person_t::operator=(const Person_t& pr)			//operator =
{
	if (this == &pr)  // check for self-assignment by comparing the addresses
		return *this;
	m_name = pr.m_name;
	m_age = pr.m_age;
	return *this;
}

bool Person_t::operator==(const Person_t& pr) {				// Operator ==
	return m_name == pr.m_name;
}