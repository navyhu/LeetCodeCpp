#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	int scheduleCourse(vector<vector<int>>& courses) {
		multimap<int, int> endDay2Len;
		for (auto& course : courses)
			endDay2Len.insert(make_pair(course[1], course[0]));

		vector<int> results;
		for (auto& day2Len : endDay2Len) {
			if (results.size() == 0) {
				results.push_back(day2Len.second);
				continue;
			}
			for (int i = results.size() - 1; i >= 0; i--) {
				int newLen = results[i] + day2Len.second;
				if (i == results.size() - 1 && newLen <= day2Len.first)
					results.push_back(results[i] + day2Len.second);
				else if (newLen <= day2Len.first && newLen < results[i + 1])
					results[i + 1] = newLen;
			}
			results[0] = day2Len.second < results[0] ? day2Len.second : results[0];
		}

		return results.size();
	}
};

int main() {
	Solution test;

	vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
	for (auto& course : courses)
		cout<<course[0]<<", "<<course[1]<<endl;

	cout<<test.scheduleCourse(courses)<<endl;

	return 0;
}
