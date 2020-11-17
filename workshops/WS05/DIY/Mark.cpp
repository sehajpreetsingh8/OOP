//Name -Sehajpreet Singh
//ID - 124314204

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
	void Mark::setEmpty() {
		m_mark = -1;
	}
	Mark::Mark() {
		m_mark = 0;
	}
	Mark::Mark(int number) {
		if (number >= 0 && number <= 100) {
			m_mark = number;
		}
		else
		{
			setEmpty();
		}
	}

	Mark::operator int() const {
		int o_mark = 0;
		if (*this) {	
			o_mark = m_mark;
		}
		return o_mark;
	}

	Mark& Mark::operator += (const int& RValue) {
		if (*this) {
			m_mark += RValue;
			if (!*this) {
				setEmpty();
			}
		}
		return *this;
	}
	Mark& Mark::operator=(const int& RValue) {
		
			m_mark = RValue;
			if (!*this) {
				setEmpty();
			}
		
		return *this;
	}

	Mark::operator bool() const {
		bool isValid = false;
		if (m_mark >= 0 && m_mark <= 100) {
			isValid = true;
		}
		return isValid;
	}

	Mark::operator char() const {
		char grade = 'X';

		if (m_mark >= 80 && m_mark <= 100)
		{
			grade = 'A';
		}

		else if (m_mark >= 70 && m_mark < 80)
		{
			grade = 'B';
		}

		else if (m_mark >= 60 && m_mark < 70)
		{
			grade = 'C';
		}

		else if (m_mark >= 50 && m_mark < 60)
		{
			grade = 'D';
		}
		else if (m_mark >= 0 && m_mark < 50)
		{
			grade = 'F';

		}
		return grade;

	}

	Mark::operator double()const {

		float scale = 0.0f;


		if (m_mark >= 80 && m_mark <= 100)
		{
			scale = 4.0f;
		}

		else if (m_mark >= 70 && m_mark < 80)
		{
			scale = 3.0f;
		}

		else if (m_mark >= 60 && m_mark < 70)
		{
			scale = 2.0f;
		}

		else if (m_mark >= 50 && m_mark < 60)
		{
			scale = 1.0f;
		}
		else if (m_mark >= 0 && m_mark < 50)
		{
			scale = 0.0f;
		}

		return scale;
	}

	int operator += (int& LValue, const Mark& ROper) {
		
		if (ROper) {
			LValue += int(ROper);
		}
		return LValue;
	}
}