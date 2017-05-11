#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool isConcatenated(const string& word, int start, const set<string>& wordSet) {
		for (int i = start; i < word.size(); ++i) {
			string s(word, start, i - start + 1);
			if (wordSet.find(s) != wordSet.end() && (i - start + 1 != word.size())) {
				if (i == word.size() - 1) return true;
				if (isConcatenated(word, i + 1, wordSet)) return true;
			}
		}

		return false;
	}

	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		if (words.size() < 2) return vector<string>();

		set<string> wordSet(words.begin(), words.end());
		vector<string> result;
		for (auto word : words) {
			if(isConcatenated(word, 0, wordSet))
				result.push_back(word);
		}

		return result;
	}
};

void printVec(vector<string> words) {
	for (auto word : words)
		cout<<word<<", ";
	cout<<endl;
}

int main() {
	vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};

	printVec(words);
	Solution test;
	vector<string> result = test.findAllConcatenatedWordsInADict(words);

	printVec(result);

	return 0;
}
