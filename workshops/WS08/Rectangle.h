//Name -Sehajpreet Singh
//ID - 124314204

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
   class Rectangle: public LblShape {
	   int m_width;
	   int m_height;
   public:
	   Rectangle();
	   Rectangle(const char*cstr, int widthVal, int heightVal);
	   void getSpecs(std::istream& in);
	   void draw(std::ostream& os)const;
   };
}
#endif