#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int magicalString(int n) {
		if (n == 0) return 0;
		if (n < 4) return 1;

		vector<int> magic;
		magic.reserve(n + 1);
		magic.push_back(1);
		magic.push_back(2);
		magic.push_back(2);

		int ldx = 2;
		int total = 2;
		int result = 1;

		while (total < n - 1) {
			if (magic[total] == 1) {
				magic.push_back(2);
			} else {
				magic.push_back(1);
				result++;
			}

			if (magic[ldx] == 2) {
				if (magic[total] == 1) {
					magic.push_back(2);
				} else {
					magic.push_back(1);
					result++;
				}
				total++;
			}

			ldx++;
			total++;
		}

		for (auto num : magic)
			cout<<num;
		cout<<endl;

		if (total >= n && magic[total] == 1)
			result--;

		return result;
	}
};

int main() {
	Solution test;

	int result = test.magicalString(10000);

	cout<<result<<endl;

	return 0;
}
