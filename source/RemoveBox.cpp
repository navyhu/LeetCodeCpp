#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int removeBoxes(vector<int>& boxes) {
			int n=boxes.size();

			int*** memo = new int**[n];
			for (int i = 0; i < n; ++i) {
				memo[i] = new int*[n];
				for (int j = 0; j < n; ++j) {
					memo[i][j] = new int[n];
					for (int k = 0; k < n; ++k)
						memo[i][j][k] = 0;
				}
			}

			int result = dfs(boxes,memo,0,n - 1,0);

			// delete
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					delete[] memo[i][j];
				}
				delete[] memo[i];
			}
			delete[] memo;

			return result;
		}

		int dfs(vector<int>& boxes,int*** memo, int l,int r,int k){
			if (l>r) return 0;
			if (memo[l][r][k]!=0) return memo[l][r][k];

			while (r>l && boxes[r]==boxes[r-1]) {r--;k++;}
			memo[l][r][k] = dfs(boxes,memo,l,r-1,0) + (k+1)*(k+1);
			for (int i=l; i<r; i++){
				if (boxes[i]==boxes[r]){
					memo[l][r][k] = max(memo[l][r][k], dfs(boxes,memo,l,i,k+1) + dfs(boxes,memo,i+1,r-1,0));
				}
			}
			return memo[l][r][k];
		}
};

int main() {
	vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};

	Solution test;
	int result = test.removeBoxes(boxes);
	cout<<result<<endl;

	return result;
}
