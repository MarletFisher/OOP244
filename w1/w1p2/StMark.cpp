#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "file.h"
#include "graph.h"


using namespace std;

namespace seneca {

	bool printReport(const char* filename) {

		//cout << "printReport entered" << endl;

		//cout << filename << endl;

		StMark students[MAX_NO_RECS] = { 0 };
		int marksAmt;
		int marksArray[MAX_NO_RECS];
		int bracketMarksArray[10] = { 0 };
		int bracketArr[10] = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10 };

		if (!openFile(filename)) {
			return false;
		}
			marksAmt = readMarks(students);
		int i;
		closeFile();

		//labelLine(100, "Students' mark distribution");

		//for (i = 0; i < marksAmt; i++) {
		//	cout << students[i].mark << endl;
		//	//marksArray[i] = students[i].mark;
		//	//cout << "marksArray[i]: " +  marksArray[i] << endl;
		//}

		//cout << "end of unsorted array, beginning sorted array" << endl;

		sort(students, marksAmt);
		//cout << "students[i].mark array is now sorted" << endl;

		for (i = 0; i < marksAmt; i++) {
			//cout << students[i].mark << endl;
			marksArray[i] = students[i].mark;
			//cout << marksArray[i] << endl;
		}

		for (i = 0; i < marksAmt; i++) {

			/*cout << "assessing ";
			cout << marksArray[i] << endl;*/

			if (marksArray[i] <= 100 && marksArray[i] >= 91) {
				bracketMarksArray[0]++;
				//cout << "if statement touched" << endl;
			}
			else if (marksArray[i] <= 90 && marksArray[i] >= 81) {
				bracketMarksArray[1]++;
			}
			else if (marksArray[i] <= 80 && marksArray[i] >= 71) {
				bracketMarksArray[2]++;
			}
			else if (marksArray[i] <= 70 && marksArray[i] >= 61) {
				bracketMarksArray[3]++;
			}
			else if (marksArray[i] <= 60 && marksArray[i] >= 51) {
				bracketMarksArray[4]++;
			}
			else if (marksArray[i] <= 50 && marksArray[i] >= 41) {
				bracketMarksArray[5]++;
			}
			else if (marksArray[i] <= 40 && marksArray[i] >= 31) {
				bracketMarksArray[6]++;
			}
			else if (marksArray[i] <= 30 && marksArray[i] >= 21) {
				bracketMarksArray[7]++;
			}
			else if (marksArray[i] <= 20 && marksArray[i] >= 11) {
				bracketMarksArray[8]++;
			}
			else if (marksArray[i] <= 10 && marksArray[i] >= 0) {
				bracketMarksArray[9]++;
			}
			else {
				cout << "error reached" << endl;
			}
		}

		/*for (i = 0; i < 10; i++) {
			cout << i;
			cout << " ";
			cout << bracketMarksArray[i] << endl;
		}*/
		// Printing bracketed marks
		printGraph(bracketMarksArray, 10, "Students' mark distribution", bracketArr);

		for (i = 0; i < marksAmt; i++) {
			printf("%-3d: [%-3d] %s %s\n", i + 1, marksArray[i], students[i].name, students[i].surname);
		}

		printf("----------------------------------------\n");

		//cout << "printReport ending" << endl;
		return true;
	}

	void sort(StMark student[], int length) {
		int i;
		int j;

		for (i = 0; i < length - 1; i++) {
			for (j = 0; j < length - i - 1; j++) {
				if (student[j].mark < student[j + 1].mark) {
					//int temp = student[j+1].mark;
					StMark temp = student[j + 1];
					//cout << temp << endl;
					student[j + 1] = student[j];
					student[j] = temp;

				}
			}
		}
	}
}