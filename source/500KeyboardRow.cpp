#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		if (words.size() == 0) return words;

		vector<vector<char>> keyboard = 
		{
			{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'}, 
			{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
			{'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'}
		};

		map<char, int> keyMap;
		for (int i = 0; i < keyboard.size(); ++i) {
			for (auto ch : keyboard[i]) {
				keyMap[ch] = i;
			}
		}

		vector<string> result;

		for (auto word : words) {
			int row = keyMap[word[0]];
			for (int i = 1; i < word.size(); ++i) {
				if (keyMap[word[i]] != row) {
					row = keyMap[word[i]];
					break;
				}
			}

			if (row == keyMap[word[0]])
				result.push_back(word);
		}

		return result;
	}
};

int main() {
	vector<string> words = {"wqas", "qWei", "ixsa", "assd", "xCCj", "CnbN"};

	Solution test;
	vector<string> result = test.findWords(words);

	for (auto word : result)
		cout<<word<<", ";
	cout<<endl;
	return 0;
}
