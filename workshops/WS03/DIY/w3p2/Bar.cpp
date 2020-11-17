//Name - Sehajpreet Singh
//ID - 124314204
//email - ssingh1053


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Bar.h"
using namespace std;
namespace sdds {

	void Bar::setEmpty() {
		m_Val = -1;
		strcpy(m_title, "");

	}
	void Bar::set(const char* title, char fill, int val) {
		if (val < 0 || val>100) {
			setEmpty();
		}
		else {
			strcpy(m_title, title);
			m_fill = fill;
			m_Val = val;
		}
	}
	bool Bar::isValid()const {
		bool valid = false;
		if (m_Val > 0 && m_Val < 100) {
			valid = true;
		}
		return valid;
	}

	void Bar::draw()const {
		int i;
		if (Bar::isValid())
		{
			cout << setw(20) << left << setfill('.') << m_title << "|";
			for (i = 0; i < m_Val / 2; i++)
			{
				cout << m_fill;
			}
			cout << endl;
		}
	}
}
