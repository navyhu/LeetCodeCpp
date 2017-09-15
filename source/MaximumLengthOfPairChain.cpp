#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	int findLongestChain(vector<vector<int>>& pairs) {
		if (pairs.size() < 2) return pairs.size();

		multimap<int, int> mapFirst;
		int smallest2nd = pairs[0][1];
		for (int i = 0; i < pairs.size(); i++) {
			mapFirst.insert(pair<int, int>(pairs[i][0], i));
			if (pairs[i][1] < smallest2nd) smallest2nd = pairs[i][1];
		}

		int result = 1;
		for (auto it = mapFirst.begin(); it != mapFirst.end(); ++it) {
			cout<<"ss: "<<it->first<<", "<<smallest2nd<<", "<<result<<endl;
			if (it->first > smallest2nd) {
				result++;
				smallest2nd = pairs[it->second][1];
				for (auto it2 = it; it2 != mapFirst.end(); ++it2) {
					//cout<<"me: "<<it2->first<<", "<<it2->second<<endl;
					if (it2->first >= smallest2nd) {
						it = --it2;
						break;
					}

					if (pairs[it2->second][1] < smallest2nd) smallest2nd = pairs[it2->second][1];
				}
			}
			cout<<"dd: "<<it->first<<", "<<smallest2nd<<", "<<result<<endl;
		}

		return result;
	}
};

int main() {
	Solution test;

	vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}, {9, 10}, {3, 5}, {5, 7}};

	cout<<test.findLongestChain(pairs)<<endl;

	return 0;
}
