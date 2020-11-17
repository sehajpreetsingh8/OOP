#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator ~() const;
        Account& operator=(const int& Rvalue);
        Account& operator=(Account& ROperand);
        Account& operator+=(const double& RValue);
        Account& operator-=(const double& RValue);

    };
    double operator+(const Account& LOperand,const Account& ROperand);
    double operator += (double& LValue, const Account& ROperand);
}
#endif // SDDS_ACCOUNT_H_