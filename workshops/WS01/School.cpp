#include <iostream>
#include <cstring>
#include "School.h"
#include "File.h"

using namespace std;

namespace sdds {
    School Schools[50];

    bool loadSchools() {
        School sc;
        int snum = 0; 
        bool ok = true;
        if (openFile("schools.dat")) {
            while (ok && snum < 50) {
                ok = readCode(sc.code) && readNum(&sc.num);
                if (ok) Schools[snum++] = sc;
            }
            closeFile();
        }
        return snum == 50;
    }
    // returns true is the code arg is substring of any of the
    // codes of the target of the sch (School*) arg.
    bool hascode(const School* sch, const char scode[]) {
        int i = 0;
        bool found = false;
        
            if (strcmp(sch->code, scode) == 0) {
                found = true;
            }
        
        return found;
    }

    

    // displays all the Schools containing the code arg
    void displaySchoolsWithcode(const char code[]) {
        int i;
        bool name = true;
        for (i = 0; i < 50 && name; i++) {
            if (hascode(&Schools[i], code)) {
                cout << "416 491 5050 x " << Schools[i].num << endl;
                name = false;
            }
        }
        if (name == true) {
            cout << code << " School code not found!" << endl;
        }

        
    }
}

