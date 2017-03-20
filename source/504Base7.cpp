#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string convertToBase7(int num) {
		bool positive = true;
		if (num < 0) {
			num = -num;
			positive = false;
		}

		vector<int> base7Digits;

		while (num > 0) {
			base7Digits.push_back(num % 7);
			num /= 7;
		}

		int digitCount = base7Digits.size();
		int chCount = digitCount + (positive ? 0 : 1);
		vector<char> base7char = {'0', '1', '2', '3', '4', '5', '6'};
		string result(chCount, '-');
		for (int i = 0; i < digitCount; ++i) {
			//cout<<digitCount<<" "<<chCount<<" "<<base7Digits[i]<<endl;
			result[chCount - 1 - i] = base7char[base7Digits[i]];
		}

		return result;
	}
};

int main() {
	int num = 20;

	Solution lTest;
	string result = lTest.convertToBase7(num);

	cout<<num<<": "<<result<<endl;
}
