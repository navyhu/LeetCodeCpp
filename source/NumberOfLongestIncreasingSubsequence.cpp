#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

/**
  1 3 5 4 7
  1 -> 1, 1
  3 -> 2, 1
  4 -> 3, 1
  5 -> 3, 1
  7 -> 4, 2
  */
class Solution {
	public:
		int findNumberOfLIS(vector<int>& nums) {
			if (nums.size() < 2) return nums.size();

			int longest = 1;
			map<int, pair<int, int>> num2lenCount;
			for (auto it = nums.begin(); it != nums.end(); ++it) {
				cout<<*it<<", ";
				auto longestIt = num2lenCount.end();
				int len = 0;
				int count = 1;
				for (auto it2 = num2lenCount.begin(); it2 != num2lenCount.end(); ++it2) {
					if (it2->first < *it) {
						if (it2->second.first > len) {
							len = it2->second.first;
							longestIt = it2;
							count = it2->second.second;
						} else if (it2->second.first == len) {
							count += it2->second.second;
						}
					} else if (it2->first == *it) {
						it2->second.second += count;
					} else {
						break;
					}
				}

				if (longestIt == num2lenCount.end()) {
					if (num2lenCount.find(*it) == num2lenCount.end()) num2lenCount[*it] = pair<int, int>(1, 1);
				} else {
					if (num2lenCount.find(*it) == num2lenCount.end())
						num2lenCount[*it] = pair<int, int>(longestIt->second.first + 1, count);
					else {
						if (num2lenCount[*it].first <= longestIt->second.first)
							num2lenCount[*it] = pair<int, int>(longestIt->second.first + 1, count);
					}
				}

				longest = num2lenCount[*it].first > longest ? num2lenCount[*it].first : longest;
			}

			cout<<endl<<longest<<endl;

			int result = 0;
			for (auto it = num2lenCount.begin(); it != num2lenCount.end(); ++it) {
				cout<<it->first<<" -> "<<it->second.first<<", "<<it->second.second<<endl;
				if (it->second.first == longest) result += it->second.second;
			}

			return result;
		}
};

int main() {
	Solution test;

	vector<int> nums1 = {1, 3, 5, 4, 7};
	vector<int> nums2 = {2, 2, 2, 2, 2};
	vector<int> nums3 = {1, 2, 2, 2, 2};
	vector<int> nums4 = {1,2,4,3,5,4,7,2};
	vector<int> nums5 = {1,1,1,2,2,2,3,3,3};

	cout<<test.findNumberOfLIS(nums1)<<endl;
	cout<<test.findNumberOfLIS(nums2)<<endl;
	cout<<test.findNumberOfLIS(nums3)<<endl;
	cout<<test.findNumberOfLIS(nums4)<<endl;
	cout<<test.findNumberOfLIS(nums5)<<endl;

	return 0;
}
