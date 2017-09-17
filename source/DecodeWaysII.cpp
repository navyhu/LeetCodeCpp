#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
	int numDecodings(string s) {
		if (s.size() < 1) return 0;

		if (s[0] == '0') return 0;

		long long curTot = s[0] == '*' ? 9 : 1;
		long long preTot = 1;
		int new1 = 0;
		int new2 = 0;
		char pre = s[0];

		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '*') {
				new1 = 9;
				if (pre == '*') new2 = 15; // 11 - 19, 21 - 26
				else if (pre == '1') new2 = 9; // 11 - 19
				else if (pre == '2') new2 = 6; // 21 - 26
				else new2 = 0;
			} else {
				new1 = s[i] == '0' ? 0 : 1;
				if (pre == '*' && s[i] <= '6') new2 = 2;
				else if (pre == '0' || (pre == '2' && s[i] > '6') || pre > '2') new2 = 0;
				else new2 = 1; // *[>6], 2[<=6], 1s[i]
			}

			long long tmpTot = curTot;
			curTot = (curTot * new1 + preTot * new2) % 1000000007;
			preTot = tmpTot;
			pre = s[i];
		}

		return curTot;
	}
};

int main() {
	Solution test;

	string s = "*1*1*0";
	cout<<s<<endl;

	cout<<test.numDecodings(s)<<endl;

	return 0;
}
