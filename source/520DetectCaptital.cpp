#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		int size = word.size();

		if (size < 2)
			return true;

		bool allUpper = false;
		if (isupper(word[0]) && isupper(word[1]))
			allUpper = true;

		for (int i = 1; i < size; ++i) {
			if (allUpper) {
				if (!isupper(word[i]))
					return false;
			} else {
				if (!islower(word[i]))
					return false;
			}
		}

		return true;
	}
};
