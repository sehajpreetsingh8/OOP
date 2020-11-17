//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "File.h"
#include "Account.h"

using namespace std;
namespace sdds {
	int noOfAccounts;
	Account* accounts;

	void sort() {
		int i, j;
		Account temp;
		for (i = noOfAccounts - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (accounts[j].accBal > accounts[j + 1].accBal) {
					temp = accounts[j];
					accounts[j] = accounts[j + 1];
					accounts[j + 1] = temp;
				}
			}
		}
	}

	bool load(Account* accounts) {
		bool ok = false;
		ok = read(&accounts->accNum) && read(&accounts->accBal);
		return ok;
	}

	bool load(const char fname[]) {
		bool ok = false;

		int i = 0;
		if (openFile(fname)) {

			noOfAccounts = noOfRecords();
			accounts = new Account[noOfAccounts];
			for (i = 0; i < noOfAccounts; i++)
			{
				load(&accounts[i]);
			}
			if (i != noOfAccounts) {
				cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
			}
			else {
				ok = true;
			}
			closeFile();

		}
		else
		{
			cout << "Could not open data file: accounts.csv" << endl;
		}

		return ok;
	}

	void display(const Account* acc) {
		cout << acc->accNum << "  " << acc->accBal << endl;
	}
	void display()
	{
		int i = 0;
		cout << "Account#: Balance" << endl;
		for (i = 0; i < noOfAccounts; i++)
		{
			display(&accounts[i]);
		}

	}
	void deallocateMemory(){
		delete[] accounts;
	}
}
