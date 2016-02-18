#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

class Solution {
public:

/* 最长的回文子字符串, 时间O(n^2)
 * s[i] s[i+1] ... s[j-1] s[j]
 * s[i..j]是回文的充要条件是: s[i+1..j-1]是回文且s[i]==s[j]
*/
string longestPalindrome(string s) {
	const int len = s.length();
	if (len < 2) {
		return s;
	}
	
	char* data = new char[len*len];
	memset(data, 0, len*len);
	
	// mark[i][j]==1, 表示s[i..j]是回文
	char** mark = new char*[len];
	for (int i=0, j=0; i < len; i++, j+=len) {
		mark[i] = data+j;
	}
	
	for (int i = 0; i < len; i++) {
		mark[i][i] = 1;
	}
	for (int i = 0; i < (len-1); i++) {
		mark[i][i+1] = s[i] == s[i+1];
	}
	for (int j = 2; j < len; j++) {
		for (int i = 0; i < (len-j); i++) {
			mark[i][i+j] = (s[i] == s[i+j]) && mark[i+1][i+j-1];
		}
	}
	
	string ret = s.substr(0, 1);
	for (int j = len-1; j >= 1; j--) {
		int i = 0;
		while ( i<(len-j) && mark[i][i+j]==0 ) {
			i++;
		}
		if (i < (len-j)) {
			ret = s.substr(i, j+1);
			break;
		}
	}
	
	delete[] data;
	return ret;
}

void test() {
	test("", "");
	test("a", "a");
	test("ab", "a");
	test("abc", "a");
	test("abcbad", "abcba");
	test("abcbadefgfeda", "adefgfeda");
	test("abcbadabc", "cbadabc");
	test("aacaadaaca", "acaadaaca");
}

private:

void test(string s, string expect) {
	string ret = longestPalindrome(s);
	if (ret == expect) {
		cout << "ok " << s << endl;
	}
	else {
		cout << "error " << s << " " << expect << " " << ret << endl;
	}
}

};

#endif