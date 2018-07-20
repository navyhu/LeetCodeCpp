#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
		// first column
		int result = 0;
		result += A.size() * (1 << (A[0].size() - 1));

		// Count 1 and 0 on each column, toggling the column if #0 > #1
		for (int j = 1; j < A[0].size(); ++j) {
			int count1 = 0;
			for (int i = 0; i < A.size(); ++i) {
				if (A[i][j] == A[i][0]) count1++;
			}

			if (count1 < A.size() - count1) count1 = A.size() - count1;
			result += count1 * (1 << (A[0].size() - 1 - j));
		}

		return result;
    }
};

int main(int argc, char** argv) {
	vector<vector<int>> A = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};

	Solution lSolution;
	int result = lSolution.matrixScore(A);

	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[0].size(); ++j) {
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"Result: "<<result<<endl;
}
