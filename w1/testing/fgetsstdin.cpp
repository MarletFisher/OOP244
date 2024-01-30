#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

bool lfCheck(char* str);

int main() {

	char str[21];

	do {
		cout << "Enter something: ";
		fgets(str, 20, stdin);
	} while (!(lfCheck(str)));
	
	cout << "You entered " << str << endl;

	return 0;
}

bool lfCheck(char* str) {
	int i;
	bool valid = false;
	for (i = 1; i < 21; i++) {
		if (str[i] == '\n') {
			valid = true;
		}
	}
	return valid;
};