/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
#include "Menu.h"
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {

	Menu::Menu(const char* text, int NoOfSelections)
	{
		m_text = nullptr;
		delete[] m_text;
		m_text = new char[strlen(text) + 1];
		strcpy(m_text, text);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	std::ostream& Menu::display(std::ostream& ostr) const
	{
		ostr << m_text << endl;
		ostr << "0- Exit" << endl;
		ostr << "> " ;
		return ostr;
	}

	int& Menu::operator>>(int& Selection)
	{

		display(cout);
		Selection = getInt();
		while (Selection < 0 || Selection > m_noOfSel)
		{
			cout << "Invalid value enterd, retry[0 <= value <= "<<m_noOfSel <<"]: ";
			Selection = getInt();
		}

		return Selection;
	}

}