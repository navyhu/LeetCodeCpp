#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		int count = 0;
		int max = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (count < k) {
				count++;
				sum += nums[i];
				max = sum;
			} else {
				sum -= nums[i - k];
				sum += nums[i];
				max = sum > max ? sum : max;
			}
		}

		return double(max) / double(k);
	}
};

int main() {
	Solution test;
	//vector<int> nums = {1,12,-5,-6,50,3};
	vector<int> nums = {5};
	int k = 1;

	cout<<test.findMaxAverage(nums, k)<<endl;

	return 0;
}
