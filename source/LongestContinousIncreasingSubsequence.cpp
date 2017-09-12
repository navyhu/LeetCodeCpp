class Solution {
	public:
		int findLengthOfLCIS(vector<int>& nums) {
			if (nums.size() < 2) return nums.size();

			int longest = 1;
			int count = 1;
			int preNum = nums[0];
			for (auto it = nums.begin(); it != nums.end(); ++it) {
				if (*it <= preNum) {
					longest = longest < count ? count : longest;
					count = 1;
				} else {
					count++;
				}
				preNum = *it;
			}

			return longest < count ? count : longest;
		}
};
