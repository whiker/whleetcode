#ifndef SOLUTION
#define SOLUTION

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
			return vector<int>({min(i+1,j), max(i+1,j)});
		}
	}
	*/
	
	map<int, int> m;
	for (int i = nums.size()-1; i >= 0; --i) {
		if (m[nums[i]] != 0) {
			int j = m[nums[i]];
			return vector<int>({min(i,j)+1, max(i,j)+1});
		}
		else {
			m[target - nums[i]] = i;
		}
	}
	
	return vector<int>({-1, -1});
}

void test() {
	test(vector<int>({2, 15, 7, 1, 11}), 9);
	test(vector<int>({3, 2, 4}), 6);
}

void test(vector<int>&& nums, int target) {
	print(twoSum(nums, target));
}

void print(const vector<int>&& v) {
	cout << "[" << *v.begin();
	for_each(v.begin()+1, v.end(),
		[] (int i) { cout << ", " << i; });
	cout << "]" << endl;
}

};

#endif