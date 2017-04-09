#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		int rowCount = wall.size();
		if (rowCount == 1) {
			if (wall[0].size() == 1) return 1;
			else return 0;
		}

		map<int, int> width2Count;
		for (auto row : wall) {
			int width = 0;
			for (int i = 0; i < row.size() - 1; ++i) {
				width += row[i];
				if (width2Count.find(width) == width2Count.end()) width2Count[width] = 1;
				else width2Count[width]++;
			}
		}

		int result = 0;
		for (auto entry : width2Count) {
			result = max(result, entry.second);
		}

		return rowCount - result;
	}
};
