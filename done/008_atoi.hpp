#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

class Solution {
public:

/* 十进制 */
int myAtoi(string str) {
	const char* p = str.c_str();
	for (; *p == ' ' || *p == '\t'; ++p);
	bool negative = false;
	if (*p == '-') {  // 负号
		++p;
		negative = true;
	}
	else if (*p == '+') {  // 正号
		++p;
	}
	for (; *p == '0'; ++p);  // 跳过开始的'0'
	
	const char* q = p;
	const char* qend = p + 11;
	for (; (q != qend && *q >= '0' && *q <= '9'); ++q);
	if (q == p) {
		return 0;
	}
	if (q == qend) {
		return (negative ? INT_MIN : INT_MAX);
	}
	
	long long ret = *p - '0';
	const char* t = p+1;
	while ( t != q ) {
		ret = (ret<<3) + (ret<<1) + (*t++ - '0');
	}
	
	if (q - p == 10) {
		if (negative) {
			if (ret >= 2147483648) {
				return INT_MIN;
			}
		}
		else {
			if (ret >= 2147483647) {
				return INT_MAX;
			}
		}
	}
	
	return (negative ? -ret : ret);
}

void test() {
	test("0", 0);
	test("-0", 0);
	test("1", 1);
	test("-1", -1);
	test("+1", 1);
	test("123", 123);
	test("-123", -123);
	test("+123", 123);
	test("0123", 123);
	test("00123", 123);
	test("-00123", -123);
	test("00a123", 0);
	test("0-123", 0);
	test("1-123", 1);
	test("123a", 123);
	test("a123", 0);
	test("12a3", 12);
	test("03a123", 3);
	test("a03123", 0);
	test("3333333333", INT_MAX);
	test("-3333333333", INT_MIN);
	test("2147483647", INT_MAX);
	test("21474836470", INT_MAX);
	test("2147483647a", INT_MAX);
	test("2147483648", INT_MAX);
	test("-2147483648", INT_MIN);
	test("-21474836480", INT_MIN);
	test("-2147483647", INT_MIN+1);
}

private:

void test(string s, int expect) {
	int ret = myAtoi(s);
	if (ret == expect) {
		cout << "ok " << s << endl;
	}
	else {
		cout << "error " << s << " " << expect << " " << ret << endl;
	}
}

};

#endif