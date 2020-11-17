/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author	Sehajpreet Singh
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/13  Preliminary release
2020/11/13  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Time.h"
#include "utils.h"
#include <iomanip>
using namespace std;

namespace sdds {
	Time& Time::reset() {

		m_min = getTime();
		return *this;

	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hrs = m_min / 60;
		int mins = m_min % 60;
		ostr << setw(2)<< setfill('0')<<right << hrs << ":" << setw(2) << mins;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hrs , mins;
		char colon;
		istr >> hrs;
		istr >> colon;
		if (colon != ':'){
		istr.setstate(ios::failbit);
		}
		istr >> mins;
		m_min = hrs * 60 + mins;
		return istr;
	}

	Time::operator int() const
	{
		return m_min;
	}

	Time& Time::operator*=(int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{

		if (m_min < D.m_min)
		{
			m_min += 24 * 60;
		}
		m_min -= D.m_min;
		
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Time& rOper)
	{
		return rOper.write(os);
	}

	std::istream& operator>>(std::istream& in, Time& rOper)
	{
		return rOper.read(in);
	}

}