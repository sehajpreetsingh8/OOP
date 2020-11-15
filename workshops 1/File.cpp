#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"

using namespace std;

namespace sdds {
    FILE* fptr;
    // opens the data file and returns true is successful
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // reads the title of the School from the global fptr File pointer
    // returns true if successful
    bool readCode(char code[]) {
        return fscanf(fptr, "%s ", code) == 1;
    }
    bool readNum(int num[]) {
        return fscanf(fptr, "%d\n", num) == 1;
    }
}