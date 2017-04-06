#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string result;

		result.reserve(S.size() + S.size() / K + 1);

		int count = 0;
		for (auto ch = S.rbegin(); ch != S.rend(); ++ch) {
			if (*ch != '-') {
				if (count == K) {
					result.push_back('-');
					count = 0;
				}

				result.push_back(*ch >= 'a' ? toupper(*ch) : *ch);
				count++;
			}
		}

		reverse(result.begin(), result.end());

		return result;
	}
};

int main() {
	string S = "2-4A0r7-4k";
	int K = 3;

	Solution test;
	string result = test.licenseKeyFormatting(S, K);

	cout<<S<<endl;
	cout<<result<<endl;
	return 0;
}
