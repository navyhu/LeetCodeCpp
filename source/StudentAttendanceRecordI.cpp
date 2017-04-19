#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool checkRecord(string s) {
		bool hasA = false;
		int countL = 0;
		for (auto ch : s) {
			switch (ch) {
				case 'A':
					if (hasA) return false;
					hasA = true;
					countL = 0;
					break;
				case 'L':
					if (countL == 2) return false;
					++countL;
					break;
				default:
					countL = 0;
					break;
			}
		}

		return true;
	}
};

int main() {
	string s = "AA";

	Solution test;
	bool result = test.checkRecord(s);

	cout<<result<<endl;

	return 0;
}
