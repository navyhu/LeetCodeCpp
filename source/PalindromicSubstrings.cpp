#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
	int countSubstrings(string s) {
		if (s.size() < 2) return s.size();
		vector<int> preSubs;
		vector<int> curSubs;
		int result = 0;
		
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < preSubs.size(); j++) {
				if (preSubs[j] > 0 && s[preSubs[j] - 1] == s[i]) {
					curSubs.push_back(preSubs[j] - 1);
					result++;
				}
			}
			if (preSubs.size() > 0 && s[preSubs[preSubs.size() - 1]] == s[i]) {
				curSubs.push_back(preSubs[preSubs.size() - 1]);
				result++;
			}
			curSubs.push_back(i);
			result++;
			preSubs = curSubs;
			curSubs.clear();
		}

		return result;
	}
};

int main() {
	Solution test;

	string s = "aaa";

	cout<<s<<endl;
	cout<<test.countSubstrings(s)<<endl;

	return 0;
}
