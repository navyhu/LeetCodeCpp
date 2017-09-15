

class Solution {
	public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> set(10000, 0);
		int total = 0;
		int dup = 0;

		for (auto& num : nums) {
			total += num;
			if (set[num - 1] == 1) dup = num;
			set[num - 1] = 1;
		}

		int n = nums.size();
		int mis = (n * (n + 1)) / 2 - total + dup;

		vector<int> result{dup, mis};
		return result;
	}
};
