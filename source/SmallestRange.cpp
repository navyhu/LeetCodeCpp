#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		if (nums.size() < 1) return vector<int>();
		vector<int> vals(nums.size(), 0);
		multimap<int, int> valsMap;
		multimap<int, int> val2Idx;
		for (int i = 0; i < nums.size(); i++) {
			vals[i] = nums[i][0];
			valsMap.insert(make_pair(vals[i], i));

			for (int j = 1; j < nums[i].size(); j++)
				val2Idx.insert(make_pair(nums[i][j], i));
		}

		auto min = valsMap.begin();
		auto max = valsMap.rbegin();
		int smallest = min->first;
		int range = max->first - min->first;
		for (auto& val : val2Idx) {
			if (val.first == vals[val.second]) continue;
			for (auto it = valsMap.find(vals[val.second]); it != valsMap.end(); ++it) {
				if (it->second == val.second) {
					valsMap.erase(it);
					break;
				}
			}
			vals[val.second] = val.first;
			valsMap.insert(make_pair(val.first, val.second));

			min = valsMap.begin();
			max = valsMap.rbegin();
			int tmpRange = max->first - min->first;
			if (tmpRange < range) {
				range = tmpRange;
				smallest = min->first;

				if (min->first == nums[min->second][muns[min->second].size() - 1]) break;
			}
		}

		vector<int> result;
		result.push_back(smallest);
		result.push_back(smallest + range);

		return result;
	}
};

int main() {
	Solution test;

	//vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
	//vector<vector<int>> nums = {{1,2,3},{1,2,3},{1,2,3}};
	vector<vector<int>> nums = {{1,1},{2,2}};

	for (auto& num : nums) {
		for(auto& n : num) {
			cout<<n<<", ";
		}
		cout<<endl;
	}

	vector<int> result = test.smallestRange(nums);
	for (auto& re : result) {
		cout<<re<<endl;
	}

	return 0;
}
