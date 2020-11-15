//Name -Sehajpreet Singh
//ID - 124314204

#ifndef SDDS_Mark_H_
#define SDDS_Mark_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_mark = 0;
        
    public:
        void setEmpty();
        Mark();
        Mark(int number);
        operator int() const;
        operator bool() const;
        operator char() const;
        operator double()const;
        Mark& operator += (const int& RValue);
        Mark& operator=(const int& RValue);

    };
    int operator += (int& LValue,const Mark& ROper);

}
#endif // SDDS_Mark_H_#pragma once
