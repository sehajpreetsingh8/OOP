//Name -Sehajpreet Singh
//ID - 124314204

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
   class LblShape: public Shape  {
	   char* m_label = nullptr;
   protected:
	   const char* label() const;
   public:
	   LblShape();
	   LblShape(const LblShape& rOper) = delete;
	   LblShape& operator = (const LblShape& rOper) = delete;
	   LblShape(const char* cStr);
	   void getSpecs(std::istream& in);
	   ~LblShape();
   };
}
#endif // !SDDS_LBLSHAPE_H


