#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

class MagicDictionary {
	public:
		/** Initialize your data structure here. */
		MagicDictionary() : mMap(), mOrinDict() {
			mMap.erase(mMap.begin(), mMap.end());
			mOrinDict.erase(mOrinDict.begin(), mOrinDict.end());
		}

		/** Build a dictionary through a list of words */
		void buildDict(vector<string> dict) {
			mMap.erase(mMap.begin(), mMap.end());
			mOrinDict.erase(mOrinDict.begin(), mOrinDict.end());

			for (auto it = dict.begin(); it != dict.end(); ++it) {

				bool lErased = false;
				for (int i = 0; i < it->size(); i++) {
					string lStr = *it;
					lStr[i] = '*';

					auto it2 = mMap.find(lStr);
					if (it2 != mMap.end()) {
						string lFullStr = it2->first;
						lFullStr[i] = it2->second;
						mOrinDict.erase(mOrinDict.find(lFullStr));
						lErased = true;
					} else {
						mMap[lStr] = (*it)[i];
					}
				}

				if (!lErased) mOrinDict.insert(*it);
			}
		}

		/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
		bool search(string word) {
			if (mOrinDict.find(word) != mOrinDict.end()) return false;

			for (int i = 0; i < word.size(); i++) {
				string lStr = word;
				lStr[i] = '*';

				if (mMap.find(lStr) != mMap.end()) return true;
			}

			return false;
		}

	private:
		map<string, char> mMap;
		set<string> mOrinDict;
};

int main() {
	vector<string> dict = {"hello", "hallo", "leetcode"};

	MagicDictionary test;
	
	test.buildDict(dict);

	cout<<test.search("hello")<<endl;
	cout<<test.search("hhllo")<<endl;
	cout<<test.search("hell")<<endl;
	cout<<test.search("leetcoded")<<endl;

	return 0;
}
