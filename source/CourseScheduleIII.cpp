#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
	public:
	int scheduleCourse(vector<vector<int>>& courses) {
		multimap<int, int> endDay2Len;
		for (auto& course : courses)
			endDay2Len.insert(make_pair(course[1], course[0]));

		int len = 0;
		multiset<int> results;
		for (auto& day2Len : endDay2Len) {
			if (len + day2Len.second <= day2Len.first) {
				results.insert(day2Len.second);
				len += day2Len.second;
			} else {
				auto biggest = results.end();
				biggest--;
				if (*biggest > day2Len.second) {
					len = len + day2Len.second - *biggest;
					results.erase(biggest);
					results.insert(day2Len.second);
				}
			}
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
