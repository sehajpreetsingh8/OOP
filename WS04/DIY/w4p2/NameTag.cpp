//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "NameTag.h"
using namespace std;
namespace sdds {

	void NameTag::setName(const char* Cstr) {

		if (Cstr != nullptr)
		{
			delete[] m_name;
			m_name = new char[strlen(Cstr) + 1];
			strcpy(m_name, Cstr);
			if (strlen(m_name) > 40) {
				m_name[40] = '\0';
			}
		}
	}

	NameTag::NameTag() {
		m_name = nullptr;
		m_extension = -1;
	}

	NameTag::NameTag(const char* name) {
		m_name = nullptr;
		setName(name);
        m_extension = 0;
	}

	NameTag::NameTag(const char* name, int extension) {
		m_name = nullptr;
		m_extension = extension;
		setName(name);
	}


	bool NameTag::checkValid() {
		bool flag = false;
		if (m_name != nullptr && (m_extension ==0 ||m_extension >= 10000 && m_extension <= 99999)) {
			flag = true;
		}
		return flag;
	}

    void NameTag::flushkeys() {
        while (cin.get() != '\n');
    }

	void NameTag::print() {
		if(NameTag::checkValid()){
			string ext = "";

			if (m_extension == 0) {
				ext = "N/A";
			}
			else {
				ext = to_string(m_extension);
			}
			if (strlen(m_name) < 20) {
                cout << setw(24) << setfill('*') << "*" << endl;
                cout << setfill(' ') << setw(23) <<left << "*"  << right << "*" << endl;
                cout << "* " << setw(20) << left << m_name << " *" << endl;
                cout << setw(23) << "*" << right << "*" << endl;
                cout << "* Extension: " << setw(9) << left << ext << " *" << endl;
                cout << setw(23) <<left<< "*" << right << "*" << endl;
                cout << setw(24) << setfill('*') << "*" << endl;
            }
            else
            {
                cout << setw(44) << setfill('*') << "*" << endl;  
                cout << setfill(' ') << setw(43) << left << "*" << right << "*" << endl;
                cout << "* " << setw(40) << left << m_name << " *" << endl;
                cout << setw(43) << "*"<< right<<"*"<< endl;
                cout << "* Extension: " << setw(29) << left << ext << " *" << endl;
                cout << setw(43) << "*" << right << "*" << endl;
                cout << setw(44) << setfill('*') << "*" << endl;
            }
        }
        else
        {
            cout << "EMPTY NAMETAG!" << endl;
        }
    }
    NameTag& NameTag::read()
    {
        char name[50] = "";
        char yes;
        int extension;

        cout << "Please enter the name : ";
        cin.get(name, 50, '\n');
        flushkeys();
        setName(name);

        cout << "Would you like to enter an extension? (Y)es/(N)o: ";
        cin >> yes;
        flushkeys();
        if (yes == 'y' || yes == 'Y')
        {
            cout << "Please enter a 5 digit phone extension : ";
            cin >> extension;
            flushkeys();
            while (extension < 10000 || extension > 99999)
            {
                cout << "Invalid value [10000<=value<=99999]: ";
                cin >> extension;
                flushkeys();
            }
            m_extension = extension;
        }
        else
        {
            m_extension = 0;
        }

        return *this;
    }
    NameTag::~NameTag()
    {
        delete[] m_name;
        m_name = nullptr;
    }
}