#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		for (auto str : strs) {
			int count0 = 0;
			int count1 = 0;
			for (auto ch : str) {
				if (ch == '0') count0++;
				else count1++;
			}

			for (int i = m; i >= count0; --i) {
				for (int j = n; j >= count1; --j) {
					dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
				}
			}

			/*for (auto row : dp) {
				for (auto num : row)
					cout<<num<<" ";
				cout<<endl;
			}
			cout<<endl;*/
		}

		return dp[m][n];
	}
};

int main() {
	//vector<string> strs = {"10", "0001", "111001", "1", "0"};//{"10", "0", "1"};//{"10", "0001", "111001", "1", "0"};
	//int m = 5;
	//int n = 3;
	vector<string> strs = {"011","1","11","0","010","1","10","1","1","0","0","0","01111","011","11","00","11","10","1","0","0","0","0","101","001110","1","0","1","0","0","10","00100","0","10","1","1","1","011","11","11","10","10","0000","01","1","10","0"};
	int m = 44;
	int n = 39;
	for (auto str : strs)
		cout<<str<<", ";
	cout<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"n = "<<n<<endl;

	Solution test;

	int result = test.findMaxForm(strs, m, n);
	cout<<"result = "<<result<<endl;
	return 0;
}
