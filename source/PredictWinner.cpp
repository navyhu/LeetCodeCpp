#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int size = nums.size();

		if (size < 3 || size % 2 == 0) return true;

		int evenSum = 0;
		int oddSum = 0;

		bool odd = false;
		for (int i = 1; i < size - 1; ++i) {
			if (odd)
				oddSum += nums[i];
			else
				evenSum += nums[i];

			odd = odd ? false : true;
		}

		int newOddSum = oddSum + nums[size - 1];
		if (newOddSum >= evenSum && evenSum + nums[0] >= newOddSum) return true;
		if (newOddSum < evenSum && newOddSum + nums[0] >= evenSum) return true;

		newOddSum = oddSum + nums[0];
		if (newOddSum >= evenSum && evenSum + nums[size - 1] >= newOddSum) return true;
		if (newOddSum < evenSum && newOddSum + nums[size - 1] >= evenSum) return true;

		return false;
	}
};

int main() {
	//vector<int> nums = {270, 3, 276, 5, 2};
	vector<int> nums = {0,0,7,6,5,6,1};

	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;

	Solution test;
	bool result = test.PredictTheWinner(nums);

	cout<<result<<endl;
	return 0;
}
