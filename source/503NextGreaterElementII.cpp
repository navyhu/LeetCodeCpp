#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int size = nums.size();

		if (size == 0) return vector<int>();

		stack<pair<int, int>> valueIndex;

		vector<int> result(size, -1);
		for (int i = 0; i < size*2 - 1; ++i) {
			int ci = i;
			if (i >= size) {
				if (valueIndex.empty()) break;
				ci -= size;
			}

			while (!valueIndex.empty()) {
				auto& top = valueIndex.top();

				if (top.first >= nums[ci])
					break;
				result[top.second] = nums[ci];
				valueIndex.pop();
			}

			if (i < size)
				valueIndex.push(make_pair(nums[i], i));
		}

		return result;
	}
};

int main() {
	vector<int> nums = {1, 2, 1, 3, 1, 2, 5};

	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;

	Solution test;
	vector<int> result = test.nextGreaterElements(nums);

	for (auto num : result)
		cout<<num<<", ";
	cout<<endl;

	return 0;
}
