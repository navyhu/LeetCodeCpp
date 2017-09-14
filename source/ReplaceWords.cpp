
class Solution {
	public:
	string replaceWords(vector<string>& dict, string sentence) {
		set<string> dictSet;
		for (auto it = dict.begin(); it != dict.end(); ++it) {
			dictSet.insert(*it);
		}

		string result;
		string word;
		bool skip = false;
		for (auto ch = sentence.begin(); ch != sentence.end(); ++ch) {
			if (*ch == ' ') {
				result.append(word);
				result.push_back(*ch);
				word.clear();
				skip = false;
			} else if (!skip) {
				word.push_back(*ch);
				if (dictSet.find(word) != dictSet.end()) skip = true;
			}
		}
		result.append(word);

		return result;
	}
};
