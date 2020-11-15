
#ifndef SDDS_Vehicle_H__
#define SDDS_Vehicle_H__
namespace sdds {
    class Vehicle {
        char m_LPNum[9];
        char m_address[64];
        int m_year;
    public:
        Vehicle(const char* LPNum,int year);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os)const;
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& ostr,const Vehicle& VehicleObj);
    std::istream& operator>>(std::istream& istr, Vehicle& VehicleObj);
}
#endif