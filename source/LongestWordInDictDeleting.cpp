#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		int length = 0;
		string result;
		int size = s.size();
		for (string word : d) {
			int i = 0;
			int pos = 0;
			for (auto ch : word) {
				pos = s.find(ch, pos);

				if (pos == string::npos) {
					break;
				}

				pos++;
			}

			if (pos != string::npos) {
				int wordSize = word.size();
				if (wordSize > length) {
					length = wordSize;
					result = word;
				} else if (wordSize== length) {
					if (word < result)
						result = word;
				}
			}
		}

		return result;
	}
};

int main() {
	//string s = "abpcplea";
	//vector<string> d = {"ale","apple","monkey","plea"};
	string s = "aaa";
	vector<string> d = {"aaa","aa","a"};

	Solution lTest;
	cout<<lTest.findLongestWord(s, d)<<endl;

	int i = 0;
	for (i = 0; i < 5; ++i) {
		if (i == 6)
			break;
	}

	cout<<"i: "<<i<<endl;

	return 0;
}
