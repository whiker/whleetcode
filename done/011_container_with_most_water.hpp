#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include "print_tool.hpp"
#include "util.h"
using namespace std;

class Solution {
public:

/* 两指针法, 时间O(n) */
int maxArea(vector<int>& height) {
	int max = 0, area;
	int p = 0, q = height.size()-1;
	
	for (int i = q-p; p < q; i--) {
		if (height[p] <= height[q]) {
			area = i * height[p];
			++p;
		}
		else {
			area = i * height[q];
			--q;
		}
		if (area > max) {
			max = area;
		}
	}
	
	return max;
}

void test() {
	test({}, 0);
	test({1}, 0);
	test({1,2}, 1);
	test({1,2,3}, 2);
	test({1,2,3,4}, 4);
	test({1,5,5,2}, 5);
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