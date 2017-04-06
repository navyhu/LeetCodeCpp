#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int result = 0;
		int count = 0;

		for (auto num : nums) {
			if (num) {
				count++;
			} else if (count) {
				result = count > result ? count : result;
				count = 0;
			}
		}

		return result > count ? result : count;
	}
};
