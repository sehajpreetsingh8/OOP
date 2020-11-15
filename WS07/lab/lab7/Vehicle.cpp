#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Vehicle.h"

namespace sdds {
	Vehicle::Vehicle(const char* LPNum, int year) {
		strcpy(m_LPNum, LPNum);
		strcpy(m_address, "Factory");
		m_year = year;
	}

	void Vehicle::moveTo(const char* address) {

		if (strcmp(m_address,address) != 0)
		{		
			cout << "|" << setw(8) << right << m_LPNum << "| |"
				<< setw(20) << right << m_address << " ---> " 
				<< setw(20) << left << address << "|" << endl;
			strcpy(m_address, address);
		}
	}
	std::ostream& Vehicle::write(std::ostream& os)const {
		os <<"| "<< m_year << " | " << m_LPNum << " | " << m_address;
		return os;
	}

	std::istream& Vehicle::read(std::istream& in)
	{
		cout << "Built Year:";
		in >> m_year;
		in.ignore();
		cout << "License plate:";
		in.getline(m_LPNum, 9);
		cout << "Current location:";
		in.getline(m_address, 64);

		return in;
	}
	std::ostream& operator<<(std::ostream& ostr,const Vehicle& VehicleObj) {
		return VehicleObj.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Vehicle& VehicleObj) {
		return VehicleObj.read(istr);
	}

}