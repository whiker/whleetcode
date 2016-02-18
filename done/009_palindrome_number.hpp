#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

class Solution {
public:

bool isPalindrome(int x) {
	if (x < 0) {
		return 0;
	}
	
	char s[11];
	int len = snprintf(s, 11, "%d", x);
	char *p=s, *q=s+len-1;
	while (p <= q && *p == *q) {
		++p, --q;
	}
	
	return p > q;
}

void test() {
	test(INT_MAX, 0);
	test(INT_MIN, 0);
	test(0, 1);
	test(1, 1);
	test(10, 0);
	test(11, 1);
	test(123, 0);
	test(101, 1);
	test(-101, 0);
	test(656, 1);
	test(12321, 1);
}

private:

void test(int x, bool expect) {
	if (isPalindrome(x) == expect) {
		cout << "ok " << x << endl;
	}
	else {
		cout << "error " << x << " " << expect << " " << !expect << endl;
	}
}

};

#endif