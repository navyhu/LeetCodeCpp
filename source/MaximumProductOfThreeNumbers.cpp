

class Solution {
	public:
	int maximumProduct(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());

		if (n == 3 || nums[0] >= 0 || nums[n - 1] <= 0 || nums[n - 2] * nums[n - 3] >= nums[0] * nums[1])
			return nums[n - 1] * nums[n - 2] * nums[n - 3];

		return nums[0] * nums[1] * nums[n - 1];
	}
};
