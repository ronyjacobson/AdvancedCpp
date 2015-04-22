#include "Meeting_t.h"


Meeting_t::Meeting_t(const float start, const float end, const string& subject)				// CTOR by start, end and subject
{
	m_start = start;
	m_end = end;
	m_subject = subject;
}

Meeting_t::~Meeting_t()
{
}

Meeting_t::Meeting_t(const Meeting_t& pr) :													// Copy CTOR
{
	m_start = pr.m_start;
	m_end = pr.m_end;
	m_subject = pr.m_subject;
}


Meeting_t& Meeting_t::operator=(const Meeting_t& pr)										// Operator =
{
	if (this == &pr)  // check for self-assignment by comparing the addresses
		return *this;
	m_start = pr.m_start;
	m_end = pr.m_end;
	m_subject = pr.m_subject;
	return *this;
}

bool Meeting_t::operator==(const Meeting_t& pr) const{										// Operator ==
	return (m_start == pr.m_start) && (m_end == pr.m_end) && (m_subject == pr.m_subject);
}
