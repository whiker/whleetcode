#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include "print_tool.hpp"
#include "util.h"
using namespace std;

class Solution {
public:

int maxArea(vector<int>& height) {
	return 0;
}

void test() {
	test({}, 0);
	test({1}, 0);
	test({1,2}, 1);
	test({1,2,3}, 2);
	test({1,2,3,4}, 3);
}

private:

void test(vector<int> height, int expect) {
	int ret = maxArea(height);
	if (ret == expect) {
		cout << "ok ";
		PrintTool<int>::printVector(height);
	}
	else {
		cout << "error ";
		PrintTool<int>::printVector(height, 0);
		cout << " " << expect << " " << ret << endl;
	}
}

};

#endif