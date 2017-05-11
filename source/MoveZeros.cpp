#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int count = 0;
		for (auto num = nums.begin(); num != nums.end();) {
			if (*num == 0) {
				num = nums.erase(num);
				count++;
			} else {
				++num;
			}
		}

		for (int i = 0; i < count; ++i)
			nums.push_back(0);
	}
};

int main() {
	vector<int> nums = {0};

	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;
	Solution test;

	test.moveZeroes(nums);

	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;
}
