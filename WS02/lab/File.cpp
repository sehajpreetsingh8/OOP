//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}
	//TODO: read functions go here    
	bool read(char stuName[]) {
		return fscanf(fptr, "%[^,],", stuName) == 1;

	}
	bool read(int* stuNum) {
		return fscanf(fptr, "%d,", stuNum) == 1;
	}
	bool read(double* stuGPA) {
		return fscanf(fptr, "%lf\n", stuGPA) == 1;
	}

}