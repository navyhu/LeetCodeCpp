#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	int kInversePairs(int n, int k) {
		if (k == 0) return 1;

		vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0));
		for (int i = 1; i <= n; i++) DP[i][0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				for (int k = j; k >= j - i + 1 && k >= 0; k--) {
					DP[i][j] += DP[i - 1][k];
				}
				DP[i][j] %= 1000000007;
			}
		}

		return DP[n][k];
	}
};

int main() {
	Solution test;

	int n = 1000;
	int k = 1000;

	cout<<n<<", "<<k<<endl;
	cout<<test.kInversePairs(n, k)<<endl;

	return 0;
}
