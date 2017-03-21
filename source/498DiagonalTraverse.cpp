#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (rows == 0) return vector<int>();

		int columns = matrix[0].size();
		if (columns == 0) return vector<int>();

		int total = rows * columns;

		vector<int> result(total, 0);

		bool up = true;

		int idx = 0;
		int i = 0;
		int j = 0;
		while (true) {
			result[idx] = matrix[i][j];
			idx++;
			if (idx == total) break;

			if (up) {
				i--;
				if (i < 0) {
					i = 0;
					j++;
					if (j == columns) {
						j = columns - 1;
						i++;
					}
					up = false;
				} else {
					j++;
					if (j == columns) {
						j = columns - 1;
						i += 2;
						up = false;
					}
				}
			} else {
				i++;
				if (i == rows) {
					i--;
					j++;
					up = true;
				} else {
					j--;
					if (j < 0) {
						j = 0;
						up = true;
					}
				}
			}
		}

		return result;
	}
};

int main() {
	vector<vector<int>> matrix = 
	/*{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{10, 11, 12},
		{10, 14, 13}
	};*/
	{
		{1},
		{3},
		{2},
		{5},
		{8}
	};

	for (auto row : matrix) {
		for (auto i : row)
			cout<<i<<", ";
		cout<<endl;
	}
	cout<<endl;

	Solution test;
	vector<int> result = test.findDiagonalOrder(matrix);

	cout<<"result:"<<endl;
	for (auto num : result)
		cout<<num<<", ";
	cout<<endl;
}
