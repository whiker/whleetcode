#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include "compare_tool.hpp"
#include "print_tool.hpp"
#include "util.h"
using namespace std;

class Solution {
public:

vector<string> addOperators(string num, int target) {
	vector<string> ret;
	dfs(num, target, 0, 0, 0, "", ret);
	return ret;
}

private:

void dfs(string num, int target,
		 int pos, long prev, long mul, string path,  // 当前状态
		 vector<string>& ret) {
	int len = num.length();
	if (pos == len) {
		if (prev == target && path.length() > 0) {
			ret.push_back(path);
		}
		return;
	}
	
	len = num[pos]=='0' ? pos+1 : len;
	for (int i = pos; i < len; i++) {
		string currStr = num.substr(pos, i-pos+1);
		long curr;
		sscanf(currStr.c_str(), "%ld", &curr);
		if (pos == 0) {
			dfs(num, target, i+1, curr, curr, currStr, ret);
		}
		else {
			dfs(num, target, i+1, prev+curr, curr, path+"+"+currStr, ret);
			dfs(num, target, i+1, prev-curr, -curr, path+"-"+currStr, ret);
			dfs(num, target, i+1, prev-mul+mul*curr, mul*curr, path+"*"+currStr, ret);
		}
	}
}

public:

void test() {
	test("", 0, {});
	test("5", 5, {"5"});
	test("123", 6, {"1+2+3", "1*2*3"});
	test("232", 8, {"2*3+2", "2+3*2"});
	test("105", 5, {"1*0+5", "10-5"});
	test("00", 0, {"0+0", "0-0", "0*0"});
	test("3456237490", 9191, {});
	test("2147483648", -2147483648, {});
}

private:

void test(string num, int target, vector<string> expect) {
	vector<string> ret = addOperators(num, target);
	sort(expect.begin(), expect.end());
	sort(ret.begin(), ret.end());
	if (CompareTool<string>::compVector(ret, expect) == 0) {
		cout << "ok " << num << endl;
	}
	else {
		cout << "error " << num << " " << target << " ";
		PrintTool<string>::printVector(expect, 0);
		cout << " ";
		PrintTool<string>::printVector(ret);
	}
}

};

#endif