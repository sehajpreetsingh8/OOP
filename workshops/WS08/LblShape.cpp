//Name -Sehajpreet Singh
//ID - 124314204

#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <cstring>
using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape()
	{
		if (m_label != nullptr) {
			m_label = nullptr;
		}
	}

	LblShape::LblShape(const char* cStr)
	{
		m_label = new char[strlen(cStr) + 1];
		strcpy(m_label, cStr); 
	}

	void LblShape::getSpecs(istream& in)
	{
		char cstr[21]{};
		in.get(cstr, 21, ',');
		m_label = new char[strlen(cstr) + 1];
		strcpy(m_label, cstr);
		in.ignore();
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
	}
}