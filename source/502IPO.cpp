#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		int size = Profits.size();
		if (k < 1 || size < 1) return W;

		priority_queue<int> availableProfits;
		multimap<int, int> capital2Profit;

		for (int i = 0; i < size; ++i) {
			capital2Profit.emplace(make_pair(Capital[i], Profits[i]));
		}

		for (auto entry : capital2Profit) {
			while (entry.first > W) {
				if (availableProfits.empty()) {
					k = 0;
					break;
				}

				W += availableProfits.top();
				availableProfits.pop();
				k--;
				cout<<"k = "<<k<<endl;
			}
			if (k == 0) break;

			cout<<"pro: "<<entry.second<<endl;
			availableProfits.push(entry.second);
		}

		cout<<"k = "<<k<<endl;
		while (k > 0) {
			if (availableProfits.empty()) break;

			cout<<"k = "<<k<<endl;
			W += availableProfits.top();
			availableProfits.pop();
			if (--k == 0) break;
		}

		return W;
	}
};

int main() {
	int k = 2;
	int W = 0;
	vector<int> Profits = {1, 2, 3};
	vector<int> Capital = {0, 1, 1};

	Solution test;
	int result = test.findMaximizedCapital(k, W, Profits, Capital);

	cout<<result<<endl;
	return 0;
}
