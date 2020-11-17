#ifndef SDDS_SCHOOL_H // replace with relevant names
#define SDDS_SCHOOL_H

// Your header file content goes here
namespace sdds {
	struct School {
		char code[5];
		int num;
	
	};

	bool loadSchools();
	bool hascode(const School* sch, const char code[]);
	void displaySchoolsWithcode(const char code[]);
}
#endif