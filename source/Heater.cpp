#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void printVec(vector<int>& nums) {
	for (auto num : nums)
		cout<<num<<" ";
	cout<<endl;
}

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		if (houses[0] >= heaters[heaters.size() - 1] || heaters[0] >= houses[houses.size() - 1])
			return max(abs(houses[0] - heaters[0]), abs(houses[houses.size() - 1] - heaters[heaters.size() - 1]));

		int radius = 0;
		int lHeater = 0;
		int rHeater = 0;
		for (auto house : houses) {
			for (int j = rHeater; j < heaters.size(); ++j) {
				lHeater = rHeater = j;
				if (heaters[j] > house) {
					if (j > 0) lHeater = j - 1;
					break;
				}
			}
			radius = max(radius, min(abs(house - heaters[lHeater]), abs(heaters[rHeater] - house)));
		}

		return radius;
	}
};

int main() {
	vector<int> houses = //{1, 2, 3, 4};
	{282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
	vector<int> heaters = //{1, 4};
	{823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};

	printVec(houses);
	printVec(heaters);

	Solution test;
	int result = test.findRadius(houses, heaters);

	cout<<result<<endl;
	return 0;
}
