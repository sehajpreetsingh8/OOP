//Name -Sehajpreet Singh
//ID - 124314204

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
   class Line: public LblShape{
	   int m_length;
   public:
	   Line();
	   Line(const char* cstr, int val);
	   void getSpecs(std::istream& in);
	   void draw(std::ostream& os)const;
   };
   
}
#endif // !SDDS_LINE_H

