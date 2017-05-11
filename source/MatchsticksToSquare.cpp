#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size() < 4) return false;

		int total = 0;
		int maxNum = 0;
		for (auto num : nums) {
			total += num;
			maxNum = max(maxNum, num);
		}

		int width = total / 4;
		if (total % 4 || maxNum > width) return false;

		map<int, int> num2cnt;
		for (auto num : nums) {
			if (num2cnt.find(num) == num2cnt.end())
				num2cnt
		}
	}
};
