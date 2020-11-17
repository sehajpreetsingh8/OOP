
#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include "Vehicle.h"
namespace sdds {
    class Truck: public Vehicle{
        double m_capacity;
        double m_load;
    public:
        Truck(const char* LPNum, int year, double capacity,const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        virtual std::ostream& write(std::ostream& os);
        virtual std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& ostr, Truck& TruckObj);
    std::istream& operator>>(std::istream& istr, Truck& TruckObj);
}
#endif 
