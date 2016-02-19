#ifndef _PRINT_TOOL_HPP
#define _PRINT_TOOL_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
class PrintTool {
public:

static void printVector(std::vector<T>& v, bool isPrintEndl=true) {
	std::cout << "[";
	if (v.size() > 0) {
		std::cout << *v.begin();
		std::for_each(v.begin()+1, v.end(),
			[] (int i) { std::cout << ", " << i; });
	}
	std::cout << "]";
	if (isPrintEndl) {
		std::cout << std::endl;
	}
}

};

#endif