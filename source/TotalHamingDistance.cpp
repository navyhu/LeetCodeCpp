#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int result = 0;
		vector<int> ones(32, 0);

		for (auto num : nums) {
			int mask = 0xFFFFFFFF;
			int bitMask = 0x1;
			int bitIdx = 0;

			while (mask & num) {
				if (num & bitMask)
					ones[bitIdx]++;
				bitMask = bitMask<<1;
				bitIdx++;
				mask = mask<<1;
			}
		}

		for (auto one : ones) {
			if (one)
				result += one * (nums.size() - one);
		}

		return result;
	}
};

int main() {
	vector<int> nums = {4, 12, 2};

	for (auto num : nums)
		cout<<num<<endl;

	Solution test;
	int result = test.totalHammingDistance(nums);

	cout<<result<<endl;;
	return 0;
}
