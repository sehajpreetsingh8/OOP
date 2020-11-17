
//Name - Sehajpreet Singh
//ID - 124314204
//email - ssingh1053


#ifndef SDDS_BARCHART_H 
#define SDDS_BARCHART_H
#include "Bar.h"
namespace sdds {
	class BarChart {
		char* m_chartTitle;
		Bar* m_bars;
		char m_fill;
		int m_noOfsamples;
		int m_added;
		void setEmpty();
		bool isValid()const;

	public:

		void init(const char* title, int noOfSampels, char fill);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
	};
}
#endif