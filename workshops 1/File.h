#ifndef SDDS_FILE_H // replace with relevant names
#define SDDS_FILE_H
namespace sdds {

	bool openFile(const char filename[]);
	void closeFile();
	bool readCode(char title[]);
	bool readNum(int num[]);
}
#endif
