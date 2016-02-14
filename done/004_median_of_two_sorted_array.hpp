#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

class Solution {
public:

/* 两个有序数组的中位数, 时间O(log(m+n)) */
double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
	const int m=v1.size(), n=v2.size();
	if (m < 1 && n < 1) {
		return 0.0;
	}
	int target=(m+n-1)>>1;  // 从0算起
	
	int t = findTwoSortedArray(v1, v2, 0, m-1, 0, n-1, target);
	if ( ((m+n)&1) == 0 ) {
		int t1 = findTwoSortedArray(v1, v2, 0, m-1, 0, n-1, target+1);
		return (t+t1)/2.0;
	}
	else {
		return t;
	}
}

private:

/* 找到两个有序数组的第index个元素, 时间O(log(m+n)) */
int findTwoSortedArray(vector<int>& v1, vector<int>& v2,
					   int p1, int p2, int q1, int q2, int index) {
	if (p1 > p2) {
		return v2[q1+index];
	}
	if (q1 > q2) {
		return v1[p1+index];
	}
	
	int p3 = (p1 + p2) >> 1;  // v1[p3]比整个v1的p3个元素大
	int q3 = numOfGreaterThan(v2, q1, q2, v1[p3]);  // v1[p3]比整个v2的q3个元素大
	int ind = (p3 - p1) + (q3 - q1);  // v1[p3]比(v1[p1:p2],v2[q1:q2])的ind个元素大
	if (ind > index) {
		// v1[p3]及其右边 和 v2[q3]及其右边 的元素都不满足条件
		return findTwoSortedArray(v1, v2, p1, p3-1, q1, q3-1, index);
	}
	else if (ind < index) {
		// v1[p3]及其左边 和 v2[q3]左边 的元素都不满足条件
		return findTwoSortedArray(v1, v2, p3+1, p2, q3, q2, index-ind-1);
	}
	else {
		return v1[p3];
	}
}

/* 返回target比有序数组v中多少个元素大 */ 
int numOfGreaterThan(vector<int>& v, int low, int high, int target) {
	if (v.size()==0 || low>high || low<0 || high<0) {
		return 0;
	}
	
	int mid;
	while (low < high) {
		mid = (low + high) >> 1;
		if (target > v[mid]) {
			low = mid + 1;
		}
		else if (target < v[mid]) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	if (v[low] < target) {
		return low+1;
	}
	return low;
}

public:

void test() {
	test({}, {});  // 0
	test({}, {1});  // 1
	test({0}, {1});  // 0.5
	test({1,2}, {1,1});  // 1
	test({1,2}, {1,2,3});  // 2
	test({2,2}, {2,2});  // 2
	test({2,2,2}, {2,2});  // 2
	test({2,2}, {2,2,2});  // 2
	test({1,2,3,5}, {3,4,7,8});  // 3.5
	test({2,4,7,8}, {1,2,3,5});  // 3.5
	test({2,3,7,8}, {1,2,3,5});  // 3
	test({1,2,3,4,5,6}, {3,4});  // 3.5
	test({1,2,3,4,5,6}, {3,4,5});  // 4
	test({1,2,3}, {4,5,6});  // 3.5
	test({1,2,3,4}, {5,6,7});  // 4
}

private:

void test(vector<int> nums1, vector<int> nums2) {
	double ret = findMedianSortedArrays(nums1, nums2);
	cout << ret << endl;
}

};

#endif