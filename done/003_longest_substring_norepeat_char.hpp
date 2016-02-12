#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

class Solution {
public:

int lengthOfLongestSubstring(string s) {
	if (s.length() == 0) {
		return 0;
	}
	
	const int sLen = s.length();
	const char* str = s.c_str();
	int mark[128];
	for (int i = 0; i < 128; i++) {
		mark[i] = -1;
	}
	
	int longest = 1, len = 1;
	const char* from = str;
	mark[*from] = 0;
	
	const char *p=str+1, *repeat=NULL;
	for (int i = 1; i < sLen; ++i, ++p) {
		if (mark[*p] == -1) {
			mark[*p] = i;
			++len;
		}
		else {
			if (len > longest) {
				longest = len;
			}
			repeat = str + mark[*p];
			for (; from != repeat; ++from) {
				mark[*from] = -1;
			}
			len = p - from;
			++from;
			mark[*p] = i;
		}
	}
	
	return max(longest, len);
}

void test() {
	test("");
	test("abcabcbb");
	test("***aa*");
	test("babcad");
}

private:

void test(string s) {
	cout << lengthOfLongestSubstring(s) << " " << s << endl;
}

};

#endif