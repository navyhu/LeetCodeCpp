#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
	public:
	bool checkValidString(string s) {
		int starNum = 0;
		stack<int> left;

		for (auto& ch : s) {
			if (ch == '*') starNum++;
			else if (ch == '(') {
				left.push(starNum);
				starNum = 0;
			} else {
				if (left.empty()) {
					if (starNum == 0) return false;
					starNum--;
				} else {
					starNum += left.top();
					left.pop();
				}
			}
		}

		while (!left.empty()) {
			if (starNum == 0) return false;
			starNum += left.top() - 1;
			left.pop();
		}

		return true;
	}
};

int main() {
	Solution test;

	string s = "(*))*)";

	cout<<s<<endl;
	cout<<test.checkValidString(s)<<endl;

	return 0;
}
