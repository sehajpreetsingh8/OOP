//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#ifndef SDDS_SUBJCT_H // replace with relevant names
#define SDDS_SUBJCT_H
namespace sdds {
	class Subject
	{
		char m_code[7]; // holds the subject code (exactly 6 characters)
		int m_mark;     // the mark out of 100

		char grade()const;
	public:
		void setEmpty();
		void set(const char* code, int mark);
		float scale4()const;
		bool isValid()const;
		void display()const;


	};
}
#endif
