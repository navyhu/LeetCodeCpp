class Solution {
	public:
		bool isPossible(vector<int>& nums) {
			if (nums.size() < 3) return false;

			int total = 0;
			int count1 = 0;
			int count2 = 0;
			int count3 = 0;
			int curNum = nums[0];

			for (auto it = nums.begin(); it != nums.end(); ++it) {
				if (*it == curNum) {
					total++;
				} else {
					if (total < count1 + count2) return false;

					if (total >= count1 + count2 + count3) {
						int tmpCount1 = total - count1 - count2 - count3;
						count2 = count1;
						count1 = tmpCount1;
						count3 = total - count1 - count2;
					} else {
						count2 = count1;
						count3 = total - count2;
						count1 = 0;
					}

					if (*it - curNum != 1) {
						// there is a break, e.g. 1, 2, 3, 5, 6, 7
						if (count1 > 0 || count2 > 0) return false;
						count3 = 0;
					}

					curNum = *it;
					total = 1;
				}
			}

			if (count1 > 0 || total < count2 || total > count2 + count3) return false;

			return true;
		}
}
