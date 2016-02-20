#ifndef _COMPARE_TOOL_HPP
#define _COMPARE_TOOL_HPP

#include <vector>

template <class T>
class CompareTool {
public:

static int compVector(std::vector<T>& v1, std::vector<T>& v2) {
	const int n1 = v1.size(), n2 = v2.size();
	int i = 0, j = 0;
	for (; i < n1 && j < n2; i++, j++) {
		if (v1[i] > v2[j]) {
			return 1;
		}
		else if (v1[i] < v2[j]) {
			return -1;
		}
	}
	return n1-n2;
}

};

#endif