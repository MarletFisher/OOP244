#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "phone.h"
#include <cstdio>;

void phoneDir(const char* programTitle, const char* fileName) {

	FILE* phoneInfoFile;
	int i = 0;

	char name[MAX_NAME_LEN+1] = "";
	char areaCode[4] = "";
	char prefix[4] = "";
	char number[5] = "";

	//PhoneEntry data();

	printf("Name is initialized as %s\n", name);

	phoneInfoFile = fopen(fileName, "r");

	if (phoneInfoFile != NULL) {

		/*for (; i < 37; i++) {
			std::fscanf(phoneInfoFile, "%[^\t]\t%s\t%s\t%s\n", name, areaCode,
				prefix, number);
			std::cout << name << " " << areaCode << prefix << number << std::endl;
			
		}*/

		while (std::fscanf(phoneInfoFile, " %[^\t]\t%s\t%s\t%s\n", name, areaCode,
			prefix, number) == 4) {
			std::cout << name << " " << areaCode << prefix << number << std::endl;
		}

		fclose(phoneInfoFile);
	}
	else {
		std::cout << "Error\n" << std::endl;
	}

}

PhoneEntry::PhoneEntry() {
	name.assign("");
	areaCode.assign("");
	prefix.assign("");
	number.assign("");
}

PhoneEntry::PhoneEntry(std::string nameInput, std::string areaCodeInput, std::string prefixInput, std::string numberInput)
{
	name.assign(nameInput);
	areaCode.assign(areaCodeInput);
	prefix.assign(prefixInput);
	number.assign(numberInput);
}

PhoneEntry::~PhoneEntry() {
	std::cout << "Deconstructor entered" << std::endl;
}

void PhoneEntry::setPhoneData(const char* fileName) {
	std::cout << "Yet to be implemented" << std::endl;
}

void PhoneEntry::setName(std::string input) {
	name.assign(input);
}

void PhoneEntry::setAreaCode(std::string input) {
	areaCode.assign(input);
}

void PhoneEntry::setPrefix(std::string input) {
	prefix.assign(input);
}

void PhoneEntry::setNumber(std::string input) {
	number.assign(input);
}

std::string PhoneEntry::getName() {
	return name;
}

std::string PhoneEntry::getAreaCode() {
	return areaCode;
}

std::string PhoneEntry::getPrefix() {
	return prefix;
}

std::string PhoneEntry::getNumber() {
	return number;
}