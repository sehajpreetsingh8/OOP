//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#ifndef SDDS_TRANSCRIPT_H // replace with relevant names
#define SDDS_TRANSCRIPT_H
#include "Subjct.h"
namespace sdds {
	class Transcript
	{
		char* m_studentName; // pointer to hold the student name dynamically 
		Subject* m_subjects; // pointer to hold the subjects in the Transcript dynamically
		int m_noOfSubjects;  // Number of subjects or number of elements in the array of m_subjects.
		int m_subjectsAdded; // Number of subjects in the m_subjects array that are set to thier values properly (they are not empty)

		void setEmpty();
		bool isValid()const;
		void Title()const;
		float gpa()const;
		void footer()const;

	public:
		void init(const char* studentName, int noOfSubjects);
		bool add(const char* subject_code, int mark);
		void display()const;
		void deallocate();


	};
}
#endif