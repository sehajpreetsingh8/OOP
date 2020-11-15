//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Subjct.h"
#include "Transcript.h"
using namespace std;
namespace sdds {

	void Transcript::setEmpty() {
		m_studentName = nullptr;
		m_subjects = nullptr;
	}
	bool Transcript::isValid()const{
		bool flag = false;
		bool flagSub = true;
		int i;

		if (m_studentName != nullptr && m_subjects != nullptr)
		{
			for (i = 0; i < m_noOfSubjects && flagSub; i++)
			{
				flagSub = m_subjects[i].Subject::isValid();
			}
			if (flagSub)
			{
				flag = true;
			}
			return flag;
		
		}
	}

	void Transcript::Title()const{
		cout << m_studentName << endl;
		cout << "-----------------------------" << endl;
	}
	float Transcript::gpa()const{
		int i;
		float sum = 0.0f;
		float avg = 0.0f;
		for (i = 0; i < m_noOfSubjects; i++)
		{
			sum +=  m_subjects[i].Subject::scale4();
		}
		avg = sum / m_noOfSubjects;
		return avg;
	}
	void Transcript::footer()const{
		cout << "-----------------------------" << endl;
		cout << right << setw(29) << "GPA: " <<setprecision(1)<< gpa() << endl;
	}
	
	void Transcript::init(const char* studentName, int noOfSubjects){
		int i;
		if (studentName == NULL || noOfSubjects< 1)
		{
			Transcript::setEmpty();
		}
		else
		{
			m_noOfSubjects = noOfSubjects;
			m_subjectsAdded = 0;
			m_studentName = new char[strlen(studentName) + 1];
			strcpy(m_studentName, studentName);
			m_subjects = new Subject[m_noOfSubjects];
			for ( i = 0; i < noOfSubjects; i++)
			{
				m_subjects[i].Subject::setEmpty();
			}
		}
	}
	bool Transcript::add(const char* subject_code, int mark){
		bool flag = true, isAdd = false;
		int i;
		if (m_subjectsAdded < m_noOfSubjects)
		{
			for ( i = 0; i < m_noOfSubjects && flag; i++)
			{
				if (!m_subjects[i].Subject::isValid())
				{
					m_subjects[i].set(subject_code, mark);
					flag = false;
				}	
			}
			m_subjectsAdded++;
			isAdd = true;
		}
		return isAdd;
	}
	void Transcript::display()const{
		int i;
		if (Transcript::isValid())
		{
			Title();
			for (i = 0; i < m_noOfSubjects; i++)
			{
				m_subjects[i].Subject::display();
			}
			footer();
		}
		else
		{
			cout << "Invalid Transcirpt!" << endl;
		}
		
	}
	void Transcript::deallocate(){
		delete[] m_studentName;
		delete[] m_subjects;
	}
	

}



