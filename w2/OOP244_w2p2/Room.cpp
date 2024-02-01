#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include"Room.h"

using namespace std;
using namespace seneca;

namespace seneca {

	// sets the Room by allocating a dynamic array of guests and setting the room number 
	// (no validation is done for room number)
	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		int i;

		//cout << "set entered" << endl;
		strncpy(room.m_roomNumber, roomNumber, 6);
		room.m_noOfGuests = numberOfGuests;
		room.m_guests = new Guest[numberOfGuests];
		
		for (i = 0; i < numberOfGuests; i++) {
			room.m_guests[i].m_firstName = nullptr;
		}
		//cout << sizeof(room.m_guests) << ' 2?' << ',' << room.m_noOfGuests << ',' << room.m_roomNumber << endl;
	};

	// Prints the room number and names of the guests in the following lines with four 
	// spaces of indentaion 
	// See correct_output.txt for the exact format
	void print(const Room& room) {
		int i;
		if (room.m_guests == nullptr) {
			cout << "Empty Room!" << endl;
		}
		else {
			cout << "Room Number: " << room.m_roomNumber << endl;
			//cout << "No of Guests: " << room.m_noOfGuests << endl;
			for (i = 0; i < room.m_noOfGuests; i++) {
				cout << "    ";
				print(room.m_guests[i]);
			}
		}
		//cout << "end of set print()" << endl;
	};

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room) {
		char roomNumber[6];
		int numGuests;
		int i;

		cout << "Room number: ";
		cin >> roomNumber;
		cout << "Number of guests: ";
		cin >> numGuests;

		strcpy(room.m_roomNumber, roomNumber);
		room.m_noOfGuests = numGuests;
		room.m_guests = new Guest[numGuests];

		for (i = 0; i < numGuests; i++) {
			cout << i + 1 << ":" << endl;
			book(room.m_guests[i]);
		}

		//cout << endl;
	};

	// vacates the room by dallocating all the memory used.
	void vacate(Room& room) {
		int i;
		//cout << "vacate(room) entered" << endl;
		if (room.m_guests[0].m_firstName != nullptr) {
			//cout << "loop entered" << endl;
			for (i = 0; i < room.m_noOfGuests; i++) {
				vacate(room.m_guests[i]);
			}
		}
		//cout << "vacate(guest) loop finished" << endl;
		delete[] room.m_guests;
		//cout << "guestArr deleted" << endl;
		room.m_guests = nullptr;
		room.m_noOfGuests = 0;
		//cout << "numGuests returned to 0" << endl;
		strcpy(room.m_roomNumber, "");
		//cout << "roomNumber deleted" << endl;
		//cout << "vacate finished" << endl;
	};

}