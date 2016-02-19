#ifndef SOLUTION
#define SOLUTION

#include "print_tool.hpp"
#include "util.h"
using namespace std;

class Solution {
public:

/* 数组无序, 有且只有一个解 */
vector<int> twoSum(vector<int>& nums, int target) {
	/*
	map<int, int> m;
	for (int i = nums.size()-1; i >= 0; --i) {
		m[nums[i]] = i+1;
	}
	for (int i = nums.size()-1; i >= 0; --i) {
		int j = m[target - nums[i]];
		if (j > 0 && j != i+1) {
			return { min(i+1,j), max(i+1,j) };
		}
	}
	*/
	
	map<int, int> m;
	for (int i = nums.size()-1; i >= 0; --i) {
		if (m[nums[i]] != 0) {
			int j = m[nums[i]];
			return { min(i,j)+1, max(i,j)+1 };
		}
		else {
			m[target - nums[i]] = i;
		}
	}
	
	return { -1, -1 };
}

void test() {
	test({2, 15, 7, 1, 11}, 9);
	test({3, 2, 4}, 6);
}

private:

void test(vector<int> nums, int target) {
	PrintTool<int>::printVector(twoSum(nums, target));
}

};

#endif