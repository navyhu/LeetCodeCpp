#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a.size() != b.size())
			return a.size() > b.size() ? a.size() : b.size();

		if (a == b) return -1;

		return a.size();
	}
};
