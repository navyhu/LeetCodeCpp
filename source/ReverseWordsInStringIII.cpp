#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		auto left = s.begin();
		auto right = s.begin();

		for (right = s.begin(); right != s.end(); ++right) {
			if (*right == ' ') {
				reverse(left, right);
				left = right;
				++left;
			}
		}
		if (left != s.end())
			reverse(left, right);

		return s;
	}
};

int main() {
	string s = "Let's take LeetCode contest ";
	Solution test;
	string result = test.reverseWords(s);

	cout<<s<<endl<<result<<endl;
	return 0;
}
