#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;

		map<int, int> indexSumMap;
		indexSumMap[0] = -1;

		int length = 0;
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0)
				sum--;
			else
				sum++;

			if (indexSumMap.find(sum) != indexSumMap.end()) {
				length = (i - indexSumMap[sum] > length) ? i - indexSumMap[sum] : length;
			} else {
				indexSumMap[sum] = i;
			}
		}

		return length;
	}
};

int main() {
	vector<int> nums = {1, 1, 1, 0, 1, 1, 1, 0};

	Solution lTest;
	cout<<lTest.findMaxLength(nums)<<endl;
}
