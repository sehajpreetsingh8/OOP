//Name - Sehajpreet Singh
//ID - 124314204
//email - ssingh1053

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "BarChart.h"
using namespace std;
namespace sdds {
	void BarChart::setEmpty() {
		m_chartTitle = nullptr;
		m_bars = nullptr;
	}

	bool BarChart::isValid()const {
		bool valid = false,flag = true;
		int i;
		if (m_chartTitle != nullptr && m_bars != nullptr) {
			for (i = 0; i < m_noOfsamples && flag; i++)
			{
				flag = m_bars[i].Bar::isValid();
			}
			if (flag)
			{
				valid = true;
			}
			
		}
		return valid;
	}

	void BarChart::init(const char* title, int noOfSampels, char fill){
        int i;
        if (title == NULL || noOfSampels < 1)
        {
            BarChart::setEmpty();
        }
        else
        {
            m_noOfsamples = noOfSampels;
            m_fill = fill;
            m_added = 0;
            m_chartTitle = new char[strlen(title) + 1];
            strcpy(m_chartTitle, title);
            m_bars = new Bar[m_noOfsamples];
            for (i = 0; i < m_noOfsamples; i++)
            {
                m_bars[i].Bar::setEmpty();
            }
        }
	}
    void BarChart::add(const char* bar_title, int value)
    {
        int i;
        bool flag = true;
        if (m_added < m_noOfsamples)
        {
            for (i = 0; i < m_noOfsamples && flag; i++)
            {
                if (!m_bars[i].Bar::isValid())
                {
                    m_bars[i].set(bar_title, m_fill, value);
                    flag = false;
                }
            }
            m_added++;
        }
    }
    void BarChart::draw() const
    {
        int i = 0;
        if (BarChart::isValid())
        {
            cout << m_chartTitle << endl;
            cout << setw(70)<<setfill('-') <<"-"<< endl;
            for (i = 0; i < m_noOfsamples; i++)
            {
                m_bars[i].Bar::draw();
            }
            cout << setw(70) << setfill('-') <<"-"<< endl;
        }
        else
        {
            cout << "Invalid Chart!" << endl;
        }
    }
    void BarChart::deallocate()
    {
        delete[] m_chartTitle;
        delete[] m_bars;
        m_chartTitle = nullptr;
        m_bars = nullptr;
    }
}
