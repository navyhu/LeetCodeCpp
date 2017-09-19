#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
	bool validPalindrome(string s) {
		if (s.size() < 3) return true;

		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			if (s[left] != s[right]) {
				if (validPalindrome(s, left + 1, right)) return true;
				return validPalindrome(s, left, right - 1);
			}
			left++;
			right--;
		}

		return true;
	}

	bool validPalindrome(string s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) return false;
			left++;
			right--;
		}
		return true;
	}
};
