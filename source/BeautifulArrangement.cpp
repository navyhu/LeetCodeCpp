#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void print(vector<int>& nums) {
	for (auto num : nums)
		cout<<num<<" ";
	cout<<endl;
}

class Solution {
public:
	// idx from 0 - (N - 1)
	int countArray(vector<int>& nums, int idx) {
		/*cout<<"idx = "<<idx<<endl;
		for (int i = 0;i <= idx;i++) {
			cout<<nums[i]<<" ";
		}
		cout<<endl;
		*/
		/*
		if (idx == 1) {
			print(nums);
			if (nums[0] % 2 == 0 || 2 % nums[0] == 0) {
				swap(nums[0], nums[1]);
				print(nums);
				swap(nums[0], nums[1]);
				return 2;
			}
			return 1;
		}*/
		if (idx < 1) {
			print(nums);
			return 1;
		}
		int result = 0;
		for (int i = 0; i <= idx; ++i) {
			//cout<<"i = "<<i<<", idx = "<<idx<<", nums[i] = "<<nums[i]<<", nums[idx] = "<<nums[idx]<<endl;
			//if ((nums[idx] % (i + 1) == 0 || (i + 1) % nums[idx] == 0)
			if (nums[i] % (idx + 1) == 0 || (idx + 1) % nums[i] == 0) {
				//if (i != idx)
					//result++;
				swap(nums[idx], nums[i]);
				result += countArray(nums, idx - 1);
				swap(nums[idx], nums[i]);
			}
		}

		return result;
	}

	int countArrangement(int N) {
		if (N < 3) return N;
		vector<int> nums;
		for (int i = 1; i <= N; ++i) {
			nums.push_back(i);
		}

		return countArray(nums, N - 1);
	}
};


int main() {
	Solution lTest;
	cout<<lTest.countArrangement(6)<<endl;
	return 0;
	for (int i = 1; i < 16; i++)
		cout<<i<<": "<<lTest.countArrangement(i)<<endl;
	return 0;
}
