#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

	void findCircel(vector<vector<int>>& M, vector<int>& students, int index) {
		for (int i = 0; i < students.size(); ++i) {
			if (M[index][i] == 1 && students[i] != 1) {
				students[i] = 1;
				findCircel(M, students, i);
			}
		}
	}

	int findCircleNum(vector<vector<int>>& M) {
		int size = M.size();
		if (size < 2) return size;

		vector<int> students(size, 0);

		int res = 0;
		for (int i = 0; i < size; ++i) {
			if (students[i] == 0) {
				findCircel(M, students, i);
				res++;
			}
		}

		return res;
	}
};

int main() {
	vector<vector<int>> M = 
	{{1, 1, 0},{1, 1, 0},{0, 0, 1}};
	//{{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};

	for (auto row : M) {
		for (auto student : row) {
			cout<<student<<", ";
		}
		cout<<endl;
	}
	cout<<endl;

	Solution test;
	int result = test.findCircleNum(M);
	cout<<result<<endl;

	return 0;
}
