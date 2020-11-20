//Name -Sehajpreet Singh
//ID - 124314204

#include "Shape.h"

using namespace std;

namespace sdds {	
	ostream& operator<<(ostream& ostr, const Shape& rOper)
	{			
	   rOper.draw(ostr);
	   return ostr;
	}
	istream& operator>>(istream& istr, Shape& rOper)
	{
		rOper.getSpecs(istr);
		return istr;
	}
	Shape::~Shape()
	{
	}
}