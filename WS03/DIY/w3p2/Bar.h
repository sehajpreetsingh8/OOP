//Name - Sehajpreet Singh
//ID - 124314204
//email - ssingh1053


#ifndef SDDS_BAR_H 
#define SDDS_BAR_H
namespace sdds {
	class Bar
	{
		char m_title[20];
		char m_fill;
		int m_Val;
	public:
		void setEmpty();
		void set(const char* title, char fill, int val);
		bool isValid()const;
		void draw()const;

	};
}
#endif