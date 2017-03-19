#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int size = s.size();
		if (size < 2)
			return size;

		//cout<<"size: "<<size<<endl;
		int end = 1;
		int preLen = 1;
		int length = 1;
		for (int i = 0; i < size; i++) {
			int pos = s.find_last_of(s[i]);
			//cout<<"i: "<<i<<" c: "<<s[i]<<" pos: "<<pos<<endl;
			if (pos != string::npos && pos >= end) {
				length = 2;
				int lLen = pos - i - 1; // pos - (i + 1)
				if (lLen > 0)
					length += longestPalindromeSubseq(s.substr(i + 1, lLen));
				end = pos + 1;
			} else {
				end = i + 2;
			}

			length = preLen > length ? preLen : length;
			preLen = length;
		}

		return length;
	}

	int longestPalindromeSubseq2(string s) {
		int size = s.size();
		if (size < 2) return size;

		vector<int> lengthes= {1, 1};
		if (s[0] == s[1]) lengthes[0]++;

		if (size == 2) return lengthes[0];

		// size > 2
		for (int i = 2; i < size; ++i) {
			lengthes.push_back(1);
			int preLen = 0;
			for (int j = i - 1; j >= 0; --j) {
				int len = preLen;
				if (s[i] == s[j]) {
					len += 2;
				}
				preLen = lengthes[j];
				if (j + 1 < i)
					len = lengthes[j + 1] > len ? lengthes[j + 1] : len;
				lengthes[j] = len > lengthes[j] ? len : lengthes[j];
			}

			//for (auto len : lengthes)
			//	cout<<len<<" ";
			//cout<<endl;
		}

		return lengthes[0];
	}
};

int main() {
	//string s = "aaaaabbbbbssssaaabb";
	//string s = "aabaaba";

	string s = "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew";
	cout<<s<<endl;
	Solution lTest;
	int length = lTest.longestPalindromeSubseq2(s);
	cout<<"length: "<<length<<endl;
	return 0;
}
