#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		map<int, int> num2idx;
		for (int i = 0; i < findNums.size(); ++i) {
			num2idx[findNums[i]] = i;
		}

		vector<int> result(findNums.size(), -1);
		for (int i = 0; i < nums.size(); ++i) {
			if (num2idx.find(nums[i]) != num2idx.end()) {
				for (int j = i + 1; j < nums.size(); ++j) {
					if (nums[j] > nums[i]) {
						result[num2idx[nums[i]]] = nums[j];
						break;
					}
				}
			}
		}

		return result;
	}
};

void printVector(vector<int>& nums) {
	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;
}

int main() {
	vector<int> nums1 = {4, 1, 2};
	vector<int> nums2 = {1, 3, 4, 2};

	printVector(nums1);
	printVector(nums2);
	Solution test;
	vector<int> result = test.nextGreaterElement(nums1, nums2);

	printVector(result);
	return 0;
}
