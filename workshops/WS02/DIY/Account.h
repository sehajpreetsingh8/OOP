//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#define DATAFILE "students.csv"

namespace sdds {
	struct Account
	{
		int accNum;
		double accBal;
	};
    bool load(const char fname[]);
    void display();
    void deallocateMemory();


}
#endif // SDDS_ACCOUNT_H_
