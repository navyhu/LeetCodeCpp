#include <vector>

namespace using std;

class Solution {
	public:
		vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
			vector<vector<int>> lResult(M);

			for (int i = 0; i < M.size(); i++) {
				for (int j = 0; j < M[i].size(); j++) {
					int total = M[i][j];
					int count = 1;
					// upper row
					if (i != 0) {
						total += M[i - 1][j];
						count++;
						if (j != 0) {
							total += M[i - 1][j - 1];
							count++;
						}
						if (j != M[i].size() - 1) {
							total += M[i - 1][j + 1];
							count++;
						}
					}

					// left and right
					if (j != 0) {
						total += M[i][j - 1];
						count++;
					}
					if (j != M[i].size() - 1) {
						total += M[i][j + 1];
						count++;
					}

					// down row
					if (i != M.size() - 1) {
						total += M[i + 1][j];
						count++;
						if (j != 0) {
							total += M[i + 1][j - 1];
							count++;
						}
						if (j != M[i].size() - 1) {
							total += M[i + 1][j + 1];
							count++;
						}
					}

					lResult[i][j] = total / count;
				}
			}

			return lResult;
		}
};
