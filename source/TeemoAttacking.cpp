#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		pair<int, int> range = {0, 0};

		int result = 0;
		for (auto time : timeSeries) {
			if (time < range.second) {
				range.second = time + duration;
			} else {
				result += range.second - range.first;
				range.first = time;
				range.second = time + duration;
			}
		}

		result += (range.second - range.first);

		return result;
	}
};

int main() {
	//vector<int> timeSeries = {1, 2, 3, 5, 8};
	vector<int> timeSeries = {1, 2};
	int duration = 2;

	for (auto time : timeSeries)
		cout<<time<<" ";
	cout<<endl;
	cout<<"duration: "<<duration<<endl;

	Solution test;
	int result = test.findPoisonedDuration(timeSeries, duration);
	cout<<"result: "<<result<<endl;

	return 0;
}
