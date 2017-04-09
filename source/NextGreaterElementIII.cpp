#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
	int nextGreaterElement(int n) {
		if (n < 12) return -1;
		int result = n;

		vector<int> digits;
		digits.reserve(12);

		int preDigit = result % 10;
		result /= 10;
		digits.push_back(preDigit);
		while (result) {
			int curDigit = result % 10;
			result /= 10;

			if (preDigit > curDigit) {
				for (int i = 0; i < digits.size(); ++i) {
					if (digits[i] > curDigit) {
						swap(digits[i], curDigit);
						break;
					}
				}

				result = result * 10 + curDigit;
				for (auto digit = digits.begin(); digit != digits.end(); ++digit) {
					result = result * 10 + *digit;
				}
				return result > n ? result : -1;
			}

			preDigit = curDigit;
			digits.push_back(curDigit);
		}

		return -1;
	}
};

int main() {
	int n = 12443322;//12323;
	Solution test;

	int result = test.nextGreaterElement(n);
	cout<<n<<endl<<result<<endl;

	return 0;
}
