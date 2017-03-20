#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		map<int, int> score2Index;

		for (int i = 0; i < nums.size(); ++i) {
			score2Index[nums[i]] = i;
		}

		vector<string> prizes = {"Gold Medal", "Silver Medal", "Bronze Medal"};
		vector<string> ranks = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		vector<string> result(nums.size(), "");
		int rank = 1;
		for (auto it = score2Index.rbegin(); it != score2Index.rend(); ++it) {
			if (rank <= 3) {
				result[it->second] = prizes[rank - 1];
			} else {
				string rankStr("");
				int lRank = rank;
				while (lRank > 0) {
					rankStr = ranks[lRank % 10] + rankStr;
					lRank /= 10;
				}
				result[it->second] = rankStr;
			}
			rank++;
		}

		return result;
	}
};

int main() {
	vector<int> nums = {1, 7, 3, 4, 5, 10, 30, 60, 70, 20, 25, 74, 79};

	Solution lTest;
	vector<string> result = lTest.findRelativeRanks(nums);

	for (int i = 0; i < nums.size(); ++i) {
		cout<<nums[i]<<" : "<<result[i]<<endl;
	}
}
