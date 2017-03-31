#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> result;

		if (nums.size() > 1)
			findSubsequences(0, nums, result);

		auto subIt = result.begin();

		while (subIt != result.end()) {
			if (subIt->size() == 1) {
				subIt = result.erase(subIt);
			} else {
				++subIt;
			}
		}

		set<vector<int>> resultSet(result.begin(), result.end());
		result.assign(resultSet.begin(), resultSet.end());

		return result;
	}

	void findSubsequences(int start, vector<int>& nums, vector<vector<int>>& result) {
		if (start < nums.size() - 1)
			findSubsequences(start + 1, nums, result);

		bool exist = false;
		int curSize = result.size();
		for (int i = 0; i < curSize; ++i) {
			if (result[i][0] >= nums[start]) {
				if (result[i][0] == nums[start] && result[i].size() == 1)
					exist = true;

				vector<int> sub = {nums[start]};
				sub.insert(sub.end(), result[i].begin(), result[i].end());
				result.push_back(sub);
			}
		}

		if (!exist) {
			vector<int> sub = {nums[start]};
			result.emplace_back(sub);
		}
	}
};

int main() {
	//vector<int> nums = {4, 6, 7, 7};
	vector<int> nums = {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};

	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;

	Solution test;
	vector<vector<int>> result = test.findSubsequences(nums);

	cout<<endl;
	for (auto vec : result) {
		for (auto num : vec) {
			cout<<num<<", ";
		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}
