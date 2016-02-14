#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

class Solution {
public:

string convert(string s, int nRow) {
	const int len = s.length();
	if (nRow < 2 || len < 3 || nRow >= len) {
		return s;
	}
	if (nRow == 2) {
		char *data = new char[len+1], *p=data;
		for (int i = 0; i < len; i+=2) {
			*p++ = s[i];
		}
		for (int i = 1; i < len; i+=2) {
			*p++ = s[i];
		}
		data[len] = 0;
		string ret(data);
		delete[] data;
		return ret;
	}
	
	char* data = new char[(len<<1)];
	memset(data, 0, (len<<1));
	
	const char *src=s.c_str();
	char *p=data, *t;
	int k = 0, nCopy;
	for (int i = 0; k < len; i++) {
		if ( (i&1) == 0 ) {  // 偶数列
			nCopy = min(nRow, len-k);
			for (int j = 1; j <= nCopy; j++) {
				*p++ = *src++;
			}
		}
		else {  // 奇数列
			t = p + nRow - 2;
			nCopy = min(nRow-2, len-k);
			for (int j = 1; j <= nCopy; j++) {
				*t-- = *src++;
			}
			p += nRow;
		}
		k += nCopy;
	}
	char* dataEnd = p;
	
	char* retData = new char[len+1];
	p = retData;
	for (int i = 0; i < nRow; i++) {
		for (t = data+i; t < dataEnd; t += nRow) {
			if (*t) {
				*p++ = *t;
			}
		}
	}
	*p = 0;
	string ret(retData);
	
	delete[] data;
	delete[] retData;
	return ret;
}

void test() {
	string s = "ABCDEFGHIJKLM";
	test(s, 0, "ABCDEFGHIJKLM");
	test(s, 1, "ABCDEFGHIJKLM");
	test(s, 2, "ACEGIKMBDFHJL");
	test(s, 3, "AEIMBDFHJLCGK");
	test(s, 4, "AGMBFHLCEIKDJ");
	test(s, 5, "AIBHJCGKDFLEM");
	test(s, 6, "AKBJLCIMDHEGF");
	test(s, 7, "AMBLCKDJEIFHG");
	test(s, 8, "ABCMDLEKFJGIH");
	test(s, 9, "ABCDEMFLGKHJI");
	test(s, 10, "ABCDEFGMHLIKJ");
	test(s, 11, "ABCDEFGHIMJLK");
	test(s, 12, "ABCDEFGHIJKML");
	test(s, 13, "ABCDEFGHIJKLM");
	test(s, 14, "ABCDEFGHIJKLM");
	test(s, 15, "ABCDEFGHIJKLM");
}

private:

void test(string s, int nRow, string expect) {
	string ret = convert(s, nRow);
	if (ret == expect) {
		cout << "ok " << s << " " << nRow << endl;
	}
	else {
		cout << "error " << s << " " << nRow << " " << ret << " " << expect << endl;
	}
}

};

#endif