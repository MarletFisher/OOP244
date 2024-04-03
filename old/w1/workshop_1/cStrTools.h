#ifndef SDDS_TOOLS_H
#define SDDS_TOOLS_H

namespace sdds {

	void strCpy(char* des, const char* src);

	int strLen(const char* str);

	int strCmp(const char* s1, const char* s2);

	char toLower(char ch);

	int strnCmp(const char* s1, const char* s2, int len);

	const char* strStr(const char* str, const char* find);

	int isAlpha(char ch);

	int isSpace(char ch);

	void trim(char word[]);

	void toLowerCaseAndCopy(char des[], const char source[]);

}
#endif // !WORD_H