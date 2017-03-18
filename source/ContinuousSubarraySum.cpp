#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		set<int> sumSet;
		sumSet.insert(0);
		int count0 = 0;
		int sum = 0;
		int count = 0;
		for (auto num : nums) {
			count++;
			if (num == 0) {
				if (count0 == 1)
					return true;
				count0++;
			} else {
				count0 = 0;
			}
			if (k == 0)
				continue;

			sum += num;
			int remainder = sum % k;

			if ((sumSet.find(remainder) != sumSet.end() || remainder == 0) && count > 1 && sum >= k)
				return true;

			sumSet.insert(remainder);
		}

		return false;
	}
};

int main() {
	//vector<int> nums = {23, 2, 6, 4, 7};
	//int k = 6;
	vector<int> nums = {0, 1, 0};
	int k = -1;

	Solution lTest;
	cout<<lTest.checkSubarraySum(nums, k)<<endl;

	k = 9;
	cout<<lTest.checkSubarraySum(nums, k)<<endl;
}
