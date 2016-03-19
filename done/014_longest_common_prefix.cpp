#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include "print_tool.hpp"
#include "util.h"
using namespace std;

class Solution {
public:

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() < 2) {
		return strs.size() > 0 ? strs[0] : "";
	}
	
	string longest = longestCommonPrefixOfTwoString(strs[0], strs[1]);
	if (longest.length() == 0) {  // 及时剪枝
		return "";
	}
	for (int i = 2; i < strs.size(); i++) {
		longest = longestCommonPrefixOfTwoString(strs[i], longest);
		if (longest.length() == 0) {
			return "";
		}
	}
	return longest;
}

private:

string longestCommonPrefixOfTwoString(const string& s1, const string& s2) {
	const char *p1 = s1.c_str();
	const char *p2 = s2.c_str();
	
	while (*p1 && *p1 == *p2) {
		p1++, p2++;
	}
	return s1.substr(0, p1 - s1.c_str());
}

public:

void test() {
	test({"abcd", "abed", "accd"}, "a");
	test({"abc", "abcd", "abced"}, "abc");
}

private:

void test(vector<string> strs, string expect) {
	string ret = longestCommonPrefix(strs);
	if (ret == expect) {
		cout << "ok ";
		PrintTool<string>::printVector(strs);
	}
	else {
		cout << "error ";
		PrintTool<string>::printVector(strs, false);
		cout << " {ret: " << ret << "} {expect: " << expect << "}" << endl;
	}
}

};

#endif