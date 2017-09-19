#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	bool judgePoint24(vector<int>& nums) {
		vector<pair<int, int>> results;

		allCombines(nums, results);

		for (auto& result : results) {
			if (result.first % result.second == 0 && result.first / result.second == 24) return true;
		}

		return false;
	}

	void allCombines(vector<int>& nums, vector<pair<int, int>>& results) {
		// one and three
		for (int i = 0; i < nums.size(); i++) {
			vector<pair<int, int>> a(1, make_pair(nums[i], 1));
			vector<int> three;
			three.push_back(i == 1 ? nums[0] : nums[1]);
			three.push_back(i == 2 ? nums[0] : nums[2]);
			three.push_back(i == 3 ? nums[0] : nums[3]);

			for (int j = 0; j < three.size(); j++) {
				vector<pair<int, int>> b(1, make_pair(three[j], 1));
				pair<int, int> c(j == 1 ? three[0] : three[1], 1);
				pair<int, int> d(j == 2 ? three[0] : three[2], 1);

				vector<pair<int, int>> results2;
				resultsOf2(c, d, results2);

				vector<pair<int, int>> results3;
				resultsOfCollection(b, results2, results3);

				resultsOfCollection(a, results3, results);
			}
		}

		// two and two
		for (int i = 1; i < nums.size(); i++) {
			vector<pair<int, int>> a;
			a.push_back(make_pair(nums[0], 1));
			a.push_back(make_pair(nums[i], 1));

			vector<pair<int, int>> b;
			if (i == 1) {
				b.push_back(make_pair(nums[2], 1));
				b.push_back(make_pair(nums[3], 1));
			} else if (i == 2) {
				b.push_back(make_pair(nums[1], 1));
				b.push_back(make_pair(nums[3], 1));
			} else if (i == 3) {
				b.push_back(make_pair(nums[1], 1));
				b.push_back(make_pair(nums[2], 1));
			}

			vector<pair<int, int>> resultsA;
			resultsOf2(a[0], a[1], resultsA);

			vector<pair<int, int>> resultsB;
			resultsOf2(b[0], b[1], resultsB);

			resultsOfCollection(resultsA, resultsB, results);
		}
	}

	void resultsOfCollection(vector<pair<int, int>> a, vector<pair<int, int>> b, vector<pair<int, int>>& results) {
		for (auto& valA : a) {
			for (auto& valB : b) {
				resultsOf2(valA, valB, results);
			}
		}
	}

	void resultsOf2(pair<int, int> a, pair<int, int> b, vector<pair<int, int>>& results) {
		if (a.second * b.second != 0) {
			results.push_back(make_pair(a.first * b.second + a.second * b.first, a.second * b.second));
			results.push_back(make_pair(abs(a.first * b.second - a.second * b.first), a.second * b.second));
			results.push_back(make_pair(a.first * b.first, a.second * b.second));
		}
		if (a.second * b.first != 0) results.push_back(make_pair(a.first * b.second, a.second * b.first));
		if (b.second * a.first != 0) results.push_back(make_pair(b.first * a.second, b.second * a.first));
	}
};

int main() {
	Solution test;

	//vector<int> nums = {4, 1, 8, 7};
	//vector<int> nums = {1, 2, 1, 2};
	//vector<int> nums = {1, 2, 3, 8};
	vector<int> nums = {3, 9, 7, 7};
	for (auto& num : nums) cout<<num<<", ";
	cout<<endl;

	cout<<test.judgePoint24(nums)<<endl;

	return 0;
}
