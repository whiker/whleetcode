#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

class Solution {
public:

int reverse(int x) {
	if (x == INT_MIN) {
		return 0;
	}
	
	char s[12];
	bool flag = x < 0;
	if (flag) {
		x = -x;
	}
	
	int len = snprintf(s, 11, "%d", x);
	char *p=s, *q=s+len-1, t;
	for (; p < q; ++p,--q) {
		t = *p;
		*p = *q;
		*q = t;
	}
	
	long long r;
	sscanf(s, "%ld", &r);
	if (r > INT_MAX) {
		return 0;
	}
	if (flag) {
		return -r;
	}
	return r;
}

void test() {
	test(0, 0);
	test(-0, 0);
	test(INT_MIN, 0);
	test(INT_MAX, 0);
	test(-INT_MAX, 0);
	test(123, 321);
	test(-123, -321);
	test(1463847412, 2147483641);
	test(-1463847412, -2147483641);
	test(1563847412, 0);
	test(-1563847412, 0);
}

private:

void test(int x, int expect) {
	int ret = reverse(x);
	if (ret == expect) {
		cout << "ok " << x << endl;
	}
	else {
		cout << "error " << x << " " << expect << " " << ret << endl;
	}
}

};

#endif