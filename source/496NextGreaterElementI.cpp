#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		int findSize = findNums.size();
		vector<int> result(findSize, -1);

		if (findSize == 0 || nums.size() == 0) return result;

		auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first > right.first; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> num2Idx;

		int findIdx = 0;
		for (auto num : nums) {
			if (findIdx < findSize) {
				cout<<"push: "<<findNums[findIdx]<<", "<<findIdx<<endl;
				num2Idx.push(make_pair(findNums[findIdx], findIdx));
				++findIdx;
			}

			while (!num2Idx.empty()) {
				auto numPair = num2Idx.top();
				cout<<"top: "<<numPair.first<<", "<<numPair.second<<"   num: "<<num<<endl;
				if (numPair.first <= num) break;

				cout<<"pop: "<<numPair.first<<", "<<numPair.second<<endl;
				result[numPair.second] = num;
				num2Idx.pop();
			}
		}

		return result;
	}
};

void printVec(vector<int> nums) {
	for (auto num : nums)
		cout<<num<<", ";
	cout<<endl;
}

int main() {
	vector<int> findNums = {2, 4};
	vector<int> nums = {1, 2, 3, 4};

	printVec(findNums);
	printVec(nums);
	Solution test;
	vector<int> result = test.nextGreaterElement(findNums, nums);

	printVec(result);
	return 0;
}
