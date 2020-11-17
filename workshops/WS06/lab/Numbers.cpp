//Name- Sehajpreet Singh
//ID -124314204

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {


	Numbers::Numbers() {
		setEmpty();
		m_isOriginal = false;
	}

	Numbers::Numbers(const char* filename) {
		setEmpty();
		m_isOriginal = true;
		setFilename(filename);
		m_numCount = numberCount();
		if (m_numCount == 0 || !load()) {
			delete[] m_numbers;
			delete[] m_filename;
			setEmpty();
			m_isOriginal = false;
		}
		else {
			sort();
		}
	}
	Numbers::~Numbers() {
		save();
		delete[] m_numbers;
		delete[] m_filename;
	}

	Numbers::Numbers(const Numbers& N) {
		setEmpty();
		m_isOriginal = false;
		/**this = N;*/
		operator=(N);
	}
	Numbers& Numbers::operator=(const Numbers& N) {
		int i;
		delete[] m_numbers;
		m_numCount = N.m_numCount;
		m_numbers = new double[m_numCount];
		for (i = 0; i < m_numCount; i++)
		{
			m_numbers[i] = N.m_numbers[i];
		}
		return *this;

	}

	bool Numbers::isEmpty() const {
		return m_numbers == nullptr;
	}

	void Numbers::setEmpty() {
		m_numbers = nullptr;
		m_filename = nullptr;
		m_numCount = 0;
	}
	void Numbers::setFilename(const char* filename) {
		delete[] m_filename;
		m_filename = new char[strlen(filename) + 1];
		strcpy(m_filename, filename);
	}
	void Numbers::sort() {
		int i, j;
		double temp;
		for (i = m_numCount - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (m_numbers[j] > m_numbers[j + 1]) {
					temp = m_numbers[j];
					m_numbers[j] = m_numbers[j + 1];
					m_numbers[j + 1] = temp;
				}
			}
		}
	}

	double Numbers::average() const {
		double aver = 0.0;
		if (!isEmpty()) {
			for (int i = 0; i < m_numCount; i++)
				aver += m_numbers[i];
			aver = aver / m_numCount;
		}
		return aver;
	}
	double Numbers::min() const {
		double minVal = 0.0;
		if (!isEmpty()) {
			minVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (minVal > m_numbers[i]) minVal = m_numbers[i];
		}
		return minVal;
	}
	double Numbers::max() const {
		double maxVal = 0.0;
		if (!isEmpty()) {
			maxVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
		}
		return maxVal;
	}

	int Numbers::numberCount() const {
		ifstream filein(m_filename);
		int nChar = 0;
		char ch;
		while (filein)
		{
			ch = filein.get();
			if (ch == '\n') {
				nChar++;
			}
		}
		return nChar;
	}

	bool Numbers::load() {
		int i = 0;
		bool isRead = false;
		if (m_numCount > 0) {
			m_numbers = new double[m_numCount];
			ifstream filein(m_filename);
			while (filein && i < m_numCount)
			{
				filein >> m_numbers[i];
				if (filein) {
					i++;
				}
			}
			if (i == m_numCount)
			{
				isRead = true;
			}
		}

		return isRead;
	}


	void Numbers::save() const {
		int i;
		if (m_isOriginal && !isEmpty()) {
			ofstream fout(m_filename);
			for (i = 0; i < m_numCount; i++)
			{
				fout << m_numbers[i] << endl;
			}

		}
	}

	ostream& Numbers::display(ostream& ostr)const {
		int i;
		if (isEmpty())
		{
			ostr << "Empty List";
		}
		else
		{
			ostr << "=========================" << endl;
			if (m_isOriginal) {
				ostr << m_filename << endl;
			}
			else {
				ostr << "*** COPY ***" << endl;
			}
			for (i = 0; i < m_numCount - 1; i++)
			{
				ostr << m_numbers[i] << ", ";
			}
			ostr << m_numbers[i] << endl;
			ostr << "-------------------------" << endl;
			ostr << "Total of " << m_numCount << " number(s)" << endl;
			ostr << "Largest number:  " << max() << endl;
			ostr << "Smallest number: " << min() << endl;
			ostr << "Average :        " << average() << endl;
			ostr << "=========================";
		}
		return ostr;
	}



	Numbers& Numbers::operator += (const double& value) {
		if (!isEmpty())
		{
			int i;
			double* temp = new double[m_numCount + 1];
			for (i = 0; i < m_numCount; i++)
			{
				temp[i] = m_numbers[i];
			}
			m_numCount++;
			temp[i] = value;
			delete[] m_numbers;
			m_numbers = temp;
			sort();
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Numbers& N) {
		return N.display(os);
	}

	std::istream& operator>>(std::istream& istr, Numbers& N) {
		double value;
		istr >> value;
		N += value;
		return istr;
	}


}

