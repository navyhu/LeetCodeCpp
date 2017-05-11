#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>

using namespace std;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		if (nums.size() < 2) return 0;

		int result = 0;
		multiset<long> record;
		for (int i = nums.size() - 1; i >= 0; --i) {
			auto upperIt = record.lower_bound(2*(long)num);
			result += distance(record.begin(), upperIt);
			record.insert(2*(long)num);
		}
		for (auto num : nums) {
			auto upperIt = record.upper_bound(2*(long)num);
			result += distance(upperIt, record.end());

			record.insert(num);
		}

		return result;
	}

	int reversePairs2(vector<int>& nums) {
		if (nums.size() < 2) return 0;

		int result = 0;
		map<long long, long long> record;
		for (auto num : nums) {
			auto lowerIt = record.lower_bound(2*(long long)num);
			if (lowerIt != end()) {
				if (lowerIt->first == 2*(long long)num) {
					lowerIt--;
					if (lowerIt == end()) continue;
				}

			}
		}
	}
};

int main() {
	//vector<int> nums = {1, 3, 2, 3, 1, 1};
	//vector<int> nums = {2, 4, 3, 5, 1};
	vector<int> nums = {-5, -5};
	//vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};

	for (auto num : nums)
		cout<<num<<" ";
	cout<<endl;

	Solution test;
	int result = test.reversePairs(nums);

	cout<<"result: "<<result<<endl;
	return 0;
}
