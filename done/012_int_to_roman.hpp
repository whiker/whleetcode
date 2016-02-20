#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include "util.h"
using namespace std;

class Solution {
public:

/* 阿拉伯数字转罗马数字, 1 <= num <= 3999 */
string intToRoman(int num) {
	static const char* c[4][10] = {
		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
		{"","M","MM","MMM"}
	};
	
	char s[16], *p=s;
	p = append(p, c[3][num/1000]);
	p = append(p, c[2][(num/100)%10]);
	p = append(p, c[1][(num/10)%10]);
	p = append(p, c[0][num%10]);
	return s;
}

private:

inline char* append(char* dst, const char* src) {
	while ( (*dst++ = *src++) != '\0' );
	return --dst;
}

public:

void test() {
	test(1, "I");
	test(10, "X");
	test(100, "C");
	test(888, "DCCCLXXXVIII");
	test(999, "CMXCIX");
	test(1000, "M");
	test(3888, "MMMDCCCLXXXVIII");
	test(3999, "MMMCMXCIX");
}

private:

void test(int num, string expect) {
	string ret = intToRoman(num);
	if (ret == expect) {
		cout << "ok " << num << endl;
	}
	else {
		cout << "error " << num << " " << expect << " " << ret << endl;
	}
}

};

#endif