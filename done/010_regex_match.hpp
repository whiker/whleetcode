#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

class Solution {
public:

bool isMatch(string s, string p) {
	return isMatch(s.c_str(), p.c_str());
}

bool isMatch(const char* s, const char* p) {
	assert(s && p);
	if (*p == '\0') {
		return *s == '\0';
	}
	
	if (*(p+1) != '*') {
		assert(*p != '*');
		return ( *p==*s || (*p=='.' && *s!='\0') ) && isMatch(s+1, p+1);
	}
	
	while ( *p==*s || (*p=='.' && *s!='\0') ) {  // 可以吞掉*s
		if (isMatch(s, p+2)) {
			return true;  // 不吞掉*s时, 可以匹配成功
		}
		++s;  // 吞掉一个*s
	}
	return isMatch(s, p+2);  // 吞掉全部*s
}

void test() {
	test("", "", 1);
	test("a", "", 0);
	test("", "a", 0);
	test("", "a*", 1);
	test("aa", "a", 0);
	test("aa","aa", 1);
	test("aa", "aa.*", 1);
	test("aaa","aa", 0);
	test("aa", "a*", 1);
	test("aa", ".*", 1);
	test("ab", ".*", 1);
	test("aab", "c*a*b", 1);
	test("abbbc", "ab*c", 1);
	test("abbbc", "ab*bbc", 1);
	test("ac", "ab*c", 1);
	test("abcbcd", "a.*c.*d", 1);
	test("abc", "aa*c", 0);
	test("abc", "a.*c", 1);
	test("abc", "a.*bc", 1);
	test("abc", "aa*bc", 1);
}

private:

void test(string s, string p, bool expect) {
	if (isMatch(s, p) == expect) {
		cout << "ok " << s << " " << p << endl;
	}
	else {
		cout << "error " << s << " " << p << " " << expect << " " << !expect << endl;
	}
}

};

#endif