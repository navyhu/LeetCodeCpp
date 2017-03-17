#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<char>> board) {
	for (auto row : board) {
		for (auto cell : row)
			cout<<cell<<" ";

		cout<<endl;
	}
}

class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		char& rCur = board[click[0]][click[1]];

		if (rCur == 'M') {
			rCur = 'X';
			return board;
		}

		if (rCur != 'E')
			return board;

		int lUp = click[0] > 0 ? click[0] - 1 : 0;
		int lDown = click[0] < board.size() - 1 ? click[0] + 1 : board.size() - 1;
		int lLeft = click[1] > 0 ? click[1] - 1 : 0;
		int lRight = click[1] < board[0].size() - 1 ? click[1] + 1 : board[0].size() - 1;

		int mineCount = 0;
		for (int i = lUp; i <= lDown; i++) {
			for (int j = lLeft; j <= lRight; j++) {
				if (board[i][j] == 'M')
					mineCount++;
			}
		}

		if (mineCount != 0) {
			rCur = '0' + mineCount;
			return board;
		}

		rCur = 'B';
		vector<int> lClick = {0, 0};
		for (lClick[0] = lUp; lClick[0] <= lDown; lClick[0]++) {
			for (lClick[1] = lLeft; lClick[1] <= lRight; lClick[1]++) {
				//if (lClick[0] != click[0] || lClick[1] != click[1]) {
				if (board[lClick[0]][lClick[1]] == 'E') {
					updateBoard(board, lClick);
				}
			}
		}

		return board;
	}
};

int main() {
	/*vector<vector<char>> lBoard = {
		{'E', 'E'},
		{'E', 'E'}
	};*/
	/*vector<vector<char>> lBoard = {
		{'E', 'E', 'M'},
		{'E', 'E', 'E'}
	};*/
	/*vector<vector<char>> lBoard = {
		{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'M', 'E'},
		{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E'}
	};*/
	vector<vector<char>> lBoard = {
		{'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E', 'E', 'E', 'M'},
		{'E', 'E', 'M', 'E', 'E', 'E', 'E', 'E'},
		{'M', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'M', 'M', 'E', 'E', 'E', 'E'}
	};

	vector<int> lClick = {0, 0};

	print(lBoard);

	cout<<"click: "<<lClick[0]<<" "<<lClick[1]<<endl;

	Solution lTest;
	lBoard = lTest.updateBoard(lBoard, lClick);

	print(lBoard);

	//return 0;
	lClick[0] = 0;
	lClick[1] = 7;
	lBoard = lTest.updateBoard(lBoard, lClick);
	print(lBoard);
}
