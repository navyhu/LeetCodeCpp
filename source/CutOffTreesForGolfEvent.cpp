#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <queue>

using namespace std;

class Solution {
	public:
		int cutOffTree(vector<vector<int>>& forest) {
			int lHeight = forest.size();
			int lWidth = forest[0].size();
			int lCount = lHeight * lWidth;

			map<int, pair<int, int>> lHeightCoord;
			for (int i = 0; i < forest.size(); i++) {
				for (int j = 0; j < forest[i].size(); j++) {
					if (forest[i][j] > 1) lHeightCoord[forest[i][j]] = make_pair(i, j);
				}
			}

			int totalSteps = 0;
			pair<int, int> lCurPos(0, 0);
			for (auto it = lHeightCoord.begin(); it != lHeightCoord.end(); ++it) {
				cout<<"("<<lCurPos.first<<", "<<lCurPos.second<<") -> ["<<it->first<<" : ("<<it->second.first<<", "<<it->second.second<<")]"<<endl;
				cout<<"curPos:"<<lCurPos.first<<" ,"<<lCurPos.second<<endl;
				// get the smallest steps from lCurPos to it->second
				int lSteps = getSmallestSteps(forest, lCurPos, it->second, lHeight, lWidth);
				if (lSteps == -1) return -1;
				cout<<"Steps:"<<lSteps<<endl;

				totalSteps += lSteps;

				lCurPos = it->second;
			}

			return totalSteps;
		}

		int getSmallestSteps(vector<vector<int>>& forest, pair<int, int> pos1, pair<int, int> pos2, int height, int width) {
			int idx1 = pos1.first * width + pos1.second;
			int idx2 = pos2.first * width + pos2.second;
			if (forest[pos1.first][pos1.second] == 0) return -1;
			if (pos1.first == pos2.first && pos1.second == pos2.second) return 0;

			vector<vector<int>> visited(height, vector<int>(width, -1));
			visited[pos1.first][pos1.second] = 0;
			queue<pair<int, int>> path;
			path.push(pos1);

			while (path.size()) {
				pair<int, int> cur = path.front();
				int x = cur.first;
				int y = cur.second;

				if (x > 0 && forest[x - 1][y] > 0 && visited[x - 1][y] < 0) {
					if (x - 1 == pos2.first && y == pos2.second) return visited[x][y] + 1;
					visited[x - 1][y] = visited[x][y] + 1;
					path.push(make_pair(x - 1, y));
				}

				if (x < height - 1 && forest[x + 1][y] > 0 && visited[x + 1][y] < 0) {
					if (x + 1 == pos2.first && y == pos2.second) return visited[x][y] + 1;
					visited[x + 1][y] = visited[x][y] + 1;
					path.push(make_pair(x + 1, y));
				}

				if (y > 0 && forest[x][y - 1] > 0 && visited[x][y - 1] < 0) {
					if (x == pos2.first && y - 1 == pos2.second) return visited[x][y] + 1;
					visited[x][y - 1] = visited[x][y] + 1;
					path.push(make_pair(x, y - 1));
				}

				if (y < width - 1 && forest[x][y + 1] > 0 && visited[x][y + 1] < 0) {
					if (x == pos2.first && y + 1 == pos2.second) return visited[x][y] + 1;
					visited[x][y + 1] = visited[x][y] + 1;
					path.push(make_pair(x, y + 1));
				}

				path.pop();
			}

			return -1;
		}
};

int main() {
	Solution test;

	//vector<vector<int>> forest = {{2395,206,0,5388},{4985,2866,0,1789},{0,0,7052,0},{0,3029,3327,685},{0,0,7846,0},{0,0,1542,0},{7577,0,2902,623},{2610,9817,0,8198}};
	//vector<vector<int>> forest = {{7},{0},{3299},{3212},{8228},{0},{1320}};
	//vector<vector<int>> forest = {{1},{2}};
	//vector<vector<int>> forest = {{1, 2, 3}, {0, 0, 4}, {7, 6, 5}};
	//vector<vector<int>> forest = {{54581641,64080174,24346381,69107959},{86374198,61363882,68783324,79706116},{668150,92178815,89819108,94701471},{83920491,22724204,46281641,47531096},{89078499,18904913,25462145,60813308}};

	vector<vector<int>> forest = {{87831103,65854898,2779857,44204411,19079948,69410679,87618788},{21145230,46057433,91028222,21139600,71738422,94523119,68042744},{54778025,56455791,37381542,39938846,65988101,48544100,26370707},{23819845,17948839,19801915,60592386,77379668,80566086,9890856},{79375973,89519557,33435287,78827274,57470052,79006461,26468447},{39356777,268254,99534840,69855179,59998856,44225326,46783243},{16722565,20373932,59356985,98603797,25499764,31549350,7421797},{5770474,47592403,29997381,59695202,20261576,55571427,26565722}};

	cout<<test.cutOffTree(forest)<<endl;

	return 0;
}
