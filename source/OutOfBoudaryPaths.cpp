#include <iostream>

using namespace std;

class Solution {
public:
	void printDP(int dp[50][50][50], int m, int n, int N) {
		cout<<"Print:"<<m<<" "<<n<<" "<<N<<endl;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < N; ++k) {
					cout<<dp[i][j][k]<<" ";
				}
				cout<<";   ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	int findPaths(int m, int n, int N, int i, int j) {
		if (N == 0) return 0;

		long long dp[50][50][50] = {0};

		for (int k = 0; k < m; ++k) {
			dp[k][0][0] += 1;
			dp[k][n - 1][0] += 1;
		}

		for (int k = 0; k < n; ++k) {
			dp[0][k][0] += 1;
			dp[m - 1][k][0] += 1;
		}

		dps(dp, m, n, N, i, j);

		long long result = 0;
		for (int k = 0; k < N; ++k) {
			result += dp[i][j][k];
		}
		if (result > 1000000007) result %= 1000000007;

		return result;
	}

	int dps(long long dp[50][50][50], int m, int n, int N, int i, int j) {
		if (dp[i][j][N - 1] > 0 || N == 1) return dp[i][j][N - 1];

		dps(dp, m, n, N - 1, i, j);
		int result = 0;

		// up
		if (i > 0) {
			result += dps(dp, m, n, N - 1, i - 1, j);
			if (result > 1000000007) result %= 1000000007;
		}

		// down
		if (i < m - 1) {
			result += dps(dp, m, n, N - 1, i + 1, j);
			if (result > 1000000007) result %= 1000000007;
		}

		// left
		if (j > 0) {
			result += dps(dp, m, n, N - 1, i, j - 1);
			if (result > 1000000007) result %= 1000000007;
		}

		// right
		if (j < n - 1) {
			result += dps(dp, m, n, N - 1, i, j + 1);
			if (result > 1000000007) result %= 1000000007;
		}

		dp[i][j][N - 1] = result;

		return result;
	}
};

int main() {
	Solution test;
	int m = 2;
	int n = 2;
	int N = 2;
	int i = 0;
	int j = 0;

	int result = test.findPaths(m, n, N, i, j);
	cout<<result<<endl;

	result = test.findPaths(1, 3, 3, 0, 1);
	cout<<result<<endl;

	result = test.findPaths(30, 24, 23, 26, 12);
	cout<<result<<endl;

	return 0;
}
