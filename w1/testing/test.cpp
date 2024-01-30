#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>

 using namespace std;

int main()
{
	FILE* ptr = fopen("test.txt", "r");

	if (ptr != nullptr) {
		char cstr[61] = { 0 };
		int i;
		int num;

		i = fscanf(ptr, "%d,%60[^\n]\n", &num, cstr);

		cout << "i is " << i << endl;
		cout << cstr << endl;
	}
	else {
		cout << "no file" << endl;
	}
	fclose(ptr);

	return 0;
}