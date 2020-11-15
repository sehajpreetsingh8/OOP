#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
	void Account::setEmpty() {
		m_number = -1;
		m_balance = 0.0;
	}
	// New account
	Account::Account() {
		m_number = 0;
		m_balance = 0.0;
	}
	Account::Account(int number, double balance) {
		setEmpty();
		if (number >= 10000 && number <= 99999
			&& balance > 0) {
			m_number = number;
			m_balance = balance;
		}
	}
	std::ostream& Account::display() const {
		if (*this) {
			cout << "Acc#: ";
			if (~(*this))
				cout << "Not Set";
			else
				cout << " " << m_number << " ";
			cout << ", Balance: ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			// I (Fardad) removed the "return cout", this was a mistake
			// (copied and pasted by mistake)
			// and had no effect to the execution of the program.
			// As mentioned before we should have only
			// one return statement in a function.
		}
		else {
			cout << "Invalid Account";
		}
		return cout;
	}

	Account::operator bool() const {
		bool isValid = false;
		if (m_number == 0 || (m_number > 10000 && m_number < 99999)) {
			isValid = true;
		}
		return isValid;
	}

	Account::operator int() const {
		return m_number;
	}
	Account::operator double() const {
		return m_balance;
	}
	bool Account::operator ~() const {
		return !m_number;
	}
	Account& Account::operator=(const int& Rvalue) {
		if (Rvalue < 10000 || Rvalue > 99999) {
			setEmpty();
		}
		else if (*this)
		{
			m_number = Rvalue;
		}
		return *this;
	}

	Account& Account::operator=(Account& ROperand) {
		if (*this && ROperand) {
			m_balance = ROperand.m_balance;
			ROperand.m_balance = 0;
		}
		return *this;
	}

	Account& Account::operator+=(const double& RValue) {
		if (*this && RValue > 0) {
			m_balance += RValue;
		}
		return *this;
	}

	Account& Account::operator-=(const double& RValue) {

		if (*this && m_balance >= RValue && RValue >= 0) {
			m_balance -= RValue;
		}
		return *this;
	}

	double operator + (const Account& LOperand,const Account& ROperand) {
		double total = 0.0;
		if (LOperand && ROperand) {
			total = double(LOperand) + double(ROperand);
		}
		return total;
	}

	double operator += (double& LValue, const Account& ROperand ) {
		double total = 0.0;
		if (LValue >= 0 && ROperand) {
			total = LValue += double(ROperand);
		}
		return total;
	}

}