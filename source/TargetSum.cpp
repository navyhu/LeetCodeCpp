#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = accumulate(nums.begin(), nums.end(), 0);

		if (sum < S || (sum - S) % 2 != 0) return 0;

		int Target = (sum - S) / 2;

		vector<int> Sums(Target + 1, 0);
		Sums[0] = 1;

		for (auto num : nums) {
			for (int i = Target; i >= num; --i) {
				if (Sums[i - num])
					Sums[i] += Sums[i - num];
			}
		}

		return Sums[Target];
	}
};

int main() {
	vector<int> nums = {1, 1, 1, 1, 1};
	//vector<int> nums = {1, 2, 1};

	int S = 3;
	cout<<S<<endl;
	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;

	Solution test;
	int result = test.findTargetSumWays(nums, S);
	cout<<result<<endl;

	return 0;
}
