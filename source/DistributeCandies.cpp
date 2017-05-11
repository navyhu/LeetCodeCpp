#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int n = candies.size() / 2;

		set<int> lCandies;
		for (auto candy : candies) {
			lCandies.insert(candy);
		}

		return lCandies.size() > n ? n : lCandies.size();
	}
};
