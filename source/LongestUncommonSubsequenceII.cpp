#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool isSubsequence(const string& sub, const string& str) {
		int strIdx = 0;
		for (int i = 0; i < sub.size(); ++i) {
			while (strIdx < str.size()) {
				if (sub[i] == str[strIdx]) {
					++strIdx;
					if (i == sub.size() - 1) return true;
					break;
				}
				++strIdx;
			}

			if (strIdx == str.size()) return false;
		}

		return true;
	}

	bool isSubsequenceOfLongerStrs(const map<int, map<string, int>>& len2strs, 
			map<int, map<string, int>>::reverse_iterator curIt, const string& curStr) {
		while (curIt != len2strs.rbegin()) {
			--curIt;
			for (auto str2cnt : curIt->second) {
				if (isSubsequence(curStr, str2cnt.first)) return true;
			}
		}

		return false;
	}

	int findLUSlength(vector<string>& strs) {
		map<int, map<string, int>> len2strs;

		for (auto str : strs) {
			if (len2strs.find(str.size()) == len2strs.end()) {
				map<string, int> str2cnt;
				str2cnt[str] = 1;
				len2strs[str.size()] = str2cnt;
			} else if (len2strs[str.size()].find(str) == len2strs[str.size()].end()) {
				len2strs[str.size()][str] = 1;
			} else {
				len2strs[str.size()][str]++;
			}
		}

		for (auto entry = len2strs.rbegin(); entry != len2strs.rend(); ++entry) {
			for (auto str2cnt : entry->second) {
				if (str2cnt.second == 1 && !isSubsequenceOfLongerStrs(len2strs, entry, str2cnt.first))
					return entry->first;
			}
		}

		return -1;
	}
};

int main() {
	vector<string> strs = 
	{
		"aba", "cbc", "dea", "abaa", "cbcc", "abaa", "cbcc"
	};

	for (auto str : strs)
		cout<<str<<" ";
	cout<<endl;

	Solution test;
	int result = test.findLUSlength(strs);
	cout<<result<<endl;

	return 0;
}
