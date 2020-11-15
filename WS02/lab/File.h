//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char stuName[]);
   bool read(int* stuNum);
   bool read(double* stuGPA);
}
#endif // !SDDS_FILE_H_
