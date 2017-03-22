#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void updateAround(vector<vector<int>>& matrix, int i, int j) {
		if (matrix[i][j] == 0) return;

		int minAround = matrix[i][j];
		if (i > 0)
			minAround = matrix[i - 1][j] < minAround ? matrix[i - 1][j] : minAround;
		if (i < matrix.size() - 1)
			minAround = matrix[i + 1][j] < minAround ? matrix[i + 1][j] : minAround;
		if (j > 0)
			minAround = matrix[i][j - 1] < minAround ? matrix[i][j - 1] : minAround;
		if (j < matrix[i].size() - 1)
			minAround = matrix[i][j + 1] < minAround ? matrix[i][j + 1] : minAround;

		if (matrix[i][j] == minAround + 1)
			return;

		matrix[i][j] = minAround + 1;

		if (i > 0)
			updateAround(matrix, i - 1, j);
		if (i < matrix.size() - 1)
			updateAround(matrix, i + 1, j);
		if (j > 0)
			updateAround(matrix, i, j - 1);
		if (j < matrix[i].size() - 1)
			updateAround(matrix, i, j + 1);
	}

	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[i].size(); ++j) {
				// check the around of the current element
				updateAround(matrix, i, j);
			}
		}

		return matrix;
	}
};

void printMatrix(vector<vector<int>>& matrix) {
	for (auto row : matrix) {
		for (auto cell : row)
			cout<<cell<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main() {
	vector<vector<int>> matrix =
	{
		{0, 1, 1, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 1, 1, 0, 0},
	};

	printMatrix(matrix);

	Solution test;
	matrix = test.updateMatrix(matrix);

	printMatrix(matrix);
}
