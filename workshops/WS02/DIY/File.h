//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(int* accNum);
   bool read(double* accBal);
}
#endif // !SDDS_FILE_H_
