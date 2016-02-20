#ifndef _PRINT_TOOL_HPP
#define _PRINT_TOOL_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
class PrintTool {
public:

static void printVector(std::vector<T>& v, bool isPrintEndl=true) {
	using namespace std;
	
	cout << "[";
	if (v.size() > 0) {
		cout << *v.begin();
		for_each(v.begin()+1, v.end(),
			[] (T i) { cout << ", " << i; });
	}
	cout << "]";
	if (isPrintEndl) {
		cout << endl;
	}
}

};

#endif