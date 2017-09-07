#include <iostream>

namespace using std;

class Solution {
	public:
		bool checkPossibility(vector<int>& nums) {
			bool lOnce = false;
			for (int i = 0; i < nums.size() - 1; i++) {
				if (nums[i] > nums[i + 1]) {
					if (lOnce) return false;

					if (i > 0) {
						if (nums[i - 1] > nums[i + 1]) nums[i + 1] = nums[i];
						else nums[i] = nums[i + 1];
					} else if (i + 2 < nums.size()) {
						if (nums[i] <= nums[i + 2]) nums[i + 1] = nums[i];
						else nums[i] = nums[i + 1];
					}
					lOnce = true;
				}
			}

			return true;
		}
};

int main() {
	Solution test;

	return 0;
}
