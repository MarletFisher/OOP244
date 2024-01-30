#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string.h>
#include "Assessment.h"

using namespace std;
using namespace seneca;

namespace seneca{

	bool read(int& value, FILE* fptr) {
		return fscanf(fptr, "%d,", &value) == 1;
	};

	bool read(double& value, FILE* fptr) {
		return fscanf(fptr, "%lf,", &value) == 1;
	};

	bool read(char* cstr, FILE* fptr) {
		return fscanf(fptr, "%60[^\n]\n", cstr) == 1;
	};

	//

	bool read(Assessment& assess, FILE* fptr) {
		double tempMark;
		char tempName[60 + 1];

		//cout << "read(*obj) entered" << endl;

		if (fscanf(fptr, "%lf,%60[^\n]\n", &tempMark, tempName) == 2) {
			assess.m_mark = new double;
			*(assess.m_mark) = tempMark;

			assess.m_title = new char[strlen(tempName) + 1];
			strcpy(assess.m_title, tempName);

			return true;
		}
		else {
			return false;
		}
	};

	void freeMem(Assessment*& aptr, int size) {
		int i;

		for (i = 0; i < size; i++) {
			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;
		}

		delete[] aptr; // deleting array

		aptr = nullptr; // fixing pointer
	}

	int read(Assessment*& aptr, FILE* fptr) {
		//cout << "read(address of aptr) entered" << endl;

		int records = 0;
		int numRecords;
		int i;

		if (fscanf(fptr, "%d\n", &numRecords) != 1) {
			return 0;
		}

		aptr = new Assessment[numRecords];

		for (i = 0; i < numRecords; i++) {
			if (read(aptr[i], fptr)) {
				records++;
			}
			else {
				break;
			}
		}

		if (numRecords != records) {
			freeMem(aptr, records);
			return 0;
		}

		return numRecords;

	}
}