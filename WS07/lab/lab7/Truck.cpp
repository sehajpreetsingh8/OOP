#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Vehicle.h"
#include "Truck.h"

namespace sdds {

	Truck::Truck(const char* LPNum, int year, double capacity, const char* address):Vehicle(LPNum, year) {
		m_capacity = capacity;
		m_load = 0;
		Vehicle::moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		double oldLoad = m_load;
		m_load += cargo;
		bool isAdded = false;
		if (m_load> m_capacity)
		{
			m_load = m_capacity;
		}
		if (m_load != oldLoad) {
			isAdded = true;
		}
		return isAdded;
	}

	bool Truck::unloadCargo()
	{
		bool isUnloaded = false;
		double oldLoad = m_load;
		m_load = 0;
		if (m_load != oldLoad) {
			isUnloaded = true;
		}
		return isUnloaded;

	}

	std::ostream& Truck::write(std::ostream& os) {
		Vehicle::write(os);
		os <<" | "<<m_load<<"/"<<m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in)
	{
		Vehicle::read(in);
		cout << "Capacity: ";
		in>>m_capacity;
		cout << "Cargo: ";
		in >> m_load;

		return in;
	}
	std::ostream& operator<<(std::ostream& ostr, Truck& TruckObj) {
		return TruckObj.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Truck& TruckObj) {
		return TruckObj.read(istr);
	}

}