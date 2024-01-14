#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
#include <iostream>
#include <cstdio>
#include "cStrTools.h"



const int MAX_NAME_LEN = 50;
const int AREA_CODE_LEN = 3;
const int PREFIX_LEN = 3;
const int SUFFIX_NUM_LEN = 4;
const int MAX_PHONE_ENTRIES = 100;

class PhoneEntry {
	std::string name;
	std::string areaCode;
	std::string prefix;
	std::string number;

public:
	PhoneEntry();
	PhoneEntry(std::string, std::string, std::string, std::string);

	void setPhoneData(const char* fileName);

	void setName(std::string name);
	void setAreaCode(std::string areaCode);
	void setPrefix(std::string prefix);
	void setNumber(std::string number);

	std::string getName();
	std::string getAreaCode();
	std::string getPrefix();
	std::string getNumber();

	~PhoneEntry(); // destructor

};

void phoneDir(const char* programTitle, const char* fileName);


#endif