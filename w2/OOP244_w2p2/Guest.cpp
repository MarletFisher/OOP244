#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<string>
#include"Room.h"

using namespace std;
using namespace seneca;

namespace seneca {

	void set(Guest& guest, const char* first, const char* last, int age) {
		//cout << "function entered" << endl;
		//assess.m_title = new char[strlen(tempName) + 1];
		
		//if (first != nullptr) {
		//	//cout << "if statement entered" << endl;
		//	guest.m_firstName = new char[strlen(first) + 1];
		//	strcpy(guest.m_firstName, first);
		//}
		//else {
		//	guest.m_firstName = nullptr;
		//}
		//if (last != nullptr) {
		//	//cout << "if statement entered" << endl;
		//	guest.m_lastName = new char[strlen(last) + 1];
		//	strcpy(guest.m_lastName, last);
		//}
		//else {
		//	guest.m_lastName = nullptr;
		//}
		
		if (first != nullptr && last != nullptr && first[0] != '\0' && last[0] != '\0') {
			//cout << "if statement entered" << endl;
			guest.m_firstName = new char[strlen(first) + 1];
			//cout << "if statement entered" << endl;
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_firstName, first);
			strcpy(guest.m_lastName, last);
		}
		else {
				guest.m_firstName = nullptr;
				guest.m_lastName = nullptr;

		}
		//cout << "name assign over" << endl;

		if (age >= 18) {
			guest.m_adult = true;
		}
		else {
			guest.m_adult = false;
		}
		//cout << "function exited" << endl;
	}

	void print(const Guest& guest) {
		//cout << "print entered" << endl;
		if ( 
			guest.m_firstName == nullptr || 
			guest.m_lastName == nullptr || 
			guest.m_firstName[0] == '\0' ||
			guest.m_lastName[0] == '\0') {
			cout << "Vacated!";
		}
		else {
			cout << guest.m_firstName << " " << guest.m_lastName;
			if (!(guest.m_adult)) {
				cout << "(Child)";
			}
		}
		//cout << "end of print" << endl;
			cout << endl;
	}

	void book(Guest& guest) {
		char fName[31];
		char lName[31];
		int age;

		printf("Name: ");
		if (scanf("%s", fName) == 1) {
			guest.m_firstName = new char[strlen(fName) + 1];
			strcpy(guest.m_firstName, fName);
		};
		clearLine();

		printf("Lastname: ");
		if (scanf("%s", lName) == 1) {
			guest.m_lastName = new char[strlen(lName) + 1];
			strcpy(guest.m_lastName, lName);
		};
		clearLine();

		printf("Age: ");
		scanf("%d", &age);
		clearLine();
		
		if (age >= 18) {
			guest.m_adult = true;
		}
		else {
			guest.m_adult = false;
		}

	};

	void vacate(Guest& guest) {
		//cout << "vacate(guest) entered" << endl;
		if (guest.m_firstName != nullptr) {
			delete[] guest.m_firstName;
			guest.m_firstName = nullptr;
			//cout << "guest fname deleted" << endl;
		}
		if (guest.m_lastName != nullptr) {
			delete[] guest.m_lastName;
			guest.m_lastName = nullptr;
			//cout << "guest lname deleted" << endl;
		}
		guest.m_adult = false;
		//cout << "guest deleted" << endl;
	};

	void clearLine()
	{
		char ch;
		while ((ch = getchar()) != '\n');
	}
}