//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Subjct.h"

using namespace std;
namespace sdds {

	char Subject::grade()const {
		char grade = 'S';
		if (m_mark>=80 && m_mark<=100)
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

		else if (m_mark >= 50 && m_mark <60)
		{
			grade = 'D';
		}
		else if (m_mark >= 0 && m_mark < 50)
		{
			grade = 'F';
		}
		return grade;

	}

	void Subject::setEmpty() {
		m_mark = -1;
		strcpy(m_code, " ");
	}

	void Subject::set(const char* code, int mark) {
		if (mark<0||mark>100)
		{
			Subject::setEmpty();
		}
		else {
			m_mark = mark;
			strcpy(m_code,code);
		}
	}
	float Subject::scale4()const {
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
	bool Subject::isValid()const {

		bool flag = false;
		if (m_mark >= 0) {
			flag = true;
		}
		return flag;
	}
	void Subject::display()const {
		if (Subject::isValid())
		{
			cout << left << setw(15) << m_code;
			cout << right << setw(3) << m_mark;
			cout << fixed<< right << setw(10) << setprecision(1)<< grade() << endl;
		}
	}
}
