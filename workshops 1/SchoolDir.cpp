#include <iostream>
#include "School.h"
using namespace std;
using namespace sdds;

void flushkeys();
bool yes();


int main() {
    bool done = false;
    char code[5];
    
    loadSchools();
    cout << "Seneca School Extension search." << endl << endl;
    while (!done) {
        cout << "Enter the School code: ";
        cin >> code;
        flushkeys();
        displaySchoolsWithcode(code);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}

// flushes the keyboard
void flushkeys() {
    while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
    char ch = cin.get();
    flushkeys();
    return ch == 'y' || ch == 'Y';
}
