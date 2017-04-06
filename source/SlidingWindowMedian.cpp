#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<int> sortK(nums.begin(), nums.begin() + k);
		sort(sortK.begin(), sortK.end());

		vector<double> result;//(nums.size() - k + 1, 0);

		bool odd = k % 2;
		int medIdx = k / 2;
		int medIdx2 = medIdx;
		if (!odd)
			medIdx2 = medIdx - 1;

		int curIdx = 0;
		while (1) {
			if (!odd) {
				result.push_back((double(sortK[medIdx]) + double(sortK[medIdx2])) / 2);
			} else {
				result.push_back(sortK[medIdx]);
			}

			if (curIdx + k == nums.size())
				break;

			resortK(sortK, nums[curIdx], nums[curIdx + k]);
			curIdx++;
		}

		return result;
	}

	void resortK(vector<int>& sortK, int preNum, int curNum) {
		if (curNum == preNum) return;
		if (curNum < preNum) {
			for (int i = 0; i < sortK.size(); ++i) {
				if (sortK[i] == preNum) {
					sortK[i] = curNum;
					break;
				}
				if (sortK[i] > curNum) {
					swap(sortK[i], curNum);
				}
			}
		} else {
			for (int i = sortK.size() - 1; i >= 0; --i) {
				if (sortK[i] == preNum) {
					sortK[i] = curNum;
					break;
				}
				if (sortK[i] < curNum) {
					swap(sortK[i], curNum);
				}
			}
		}
	}
};

int main() {
	vector<int> nums = {1, 2, -1, 3, 2, -7, 9, 6, 1};
	int K = 4;

	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;

	Solution test;
	vector<double> result = test.medianSlidingWindow(nums, K);

	for (auto num : result)
		cout<<num<<", ";
	cout<<endl;

	return 0;
}
