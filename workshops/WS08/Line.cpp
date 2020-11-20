//Name -Sehajpreet Singh
//ID - 124314204

#include "Line.h"
#include "LblShape.h"
#include <cstring>
using namespace std;
namespace sdds {
    Line::Line():LblShape()
    {
        m_length = 0;        
    }
    Line::Line(const char* cstr, int val): LblShape(cstr)
    {        
        m_length = val;
    }
    void Line::getSpecs(istream& in)        
    {
        LblShape::getSpecs(in);
        in >> m_length;
        in.ignore();
    }

    void Line::draw(std::ostream& os)const
    {
        if (m_length > 0 && label() != nullptr)
        {
            os << label() << endl;
            for (int i = 0; i < m_length; i++)
            {
                os << "=";
            }
        }
    }

    

}
