#ifndef SDDS_WORD_H
#define SDDS_WORD_H

namespace sdds {

	const int SORT_BY_OCCURANCE = 1;
	const int MAX_WORD_LEN = 21;
	const int SORT_ALPHABETICALLY = 0;
	const int MAX_NO_OF_WORDS = 500;

	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};

	int searchWords(const sdds::Word words[], int num, const char word[]);
	int readWord(char* word, FILE* fptr, int maxLen);
	void addWord(sdds::Word words[], int* index, const char newWord[]);
	void title(const char* value, int len);
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void print(const sdds::Word* w, int gotoNextLine, int len);
	int findMaxLen(const sdds::Word words[], int noOfWords);
	void listWords(const sdds::Word words[], int noOfWords, const char* theTitle);
	void swap(sdds::Word* p1, sdds::Word* p2);
	void sort(sdds::Word words[], int cnt, int sortType);
	int totalCount(const sdds::Word* words, int num);
	void wordStats(const char* filename);
	void programTitle();
}
#endif // !WORD_H