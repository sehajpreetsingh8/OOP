//Name -Sehajpreet Singh
//ID - 124314204

#include "Rectangle.h"
#include "LblShape.h"
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {
	Rectangle::Rectangle() :LblShape()
	{
		m_height = 0;
		m_width = 0;
	}
	Rectangle::Rectangle(const char* cstr, int widthVal, int heightVal) : LblShape(cstr)
	{		
		m_width = widthVal;
		m_height = heightVal;
	}

	void Rectangle::getSpecs(istream& in)
	{
		LblShape::getSpecs(in);
		in >> m_width;
		in.ignore(2000, ',');
		in >> m_height;
		in.ignore(2000, '\n');
	}

	void Rectangle::draw(ostream& os)const
	{
		if (m_height != 0 && m_width != 0) {
			os << "+";
			for (int i = 0; i < (streamsize)m_width - 2; i++)
			{
				os << "-";
			}
			os << "+" << endl;

			os << "|";
			os << setw((streamsize)m_width - 2) << left << setfill(' ') << label();
			os << "|" << endl;

			for (int i = 0; i < m_height - 3; i++)
			{
				os << "|";
				os << setw((streamsize)m_width - 2) << " ";
				os << "|" << endl;

			}
			os << "+";
			for (int i = 0; i < m_width - 2; i++)
			{
				os << "-";
			}
			os << "+" ;
		}
	}

}