#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
		string lKeys;
        hGetKeysLocks(grid, lKeys);

		vector<string> lPermutations;
		hPermutation(lKeys, lPermutations);

		int lResult = -1;
		for (auto permu = lPermutations.begin(); permu != lPermutations.end(); ++permu) {
			cout<<"Ordered keys: "<<*permu<<endl;
			int lSteps = hShortestPath(grid, *permu);
			if (lSteps != -1 && (lResult == -1 || lSteps < lResult)) lResult = lSteps;
		}

		return lResult;
    }

private:
	map<char, pair<int, int> > mKeys;

	int hShortestPath(vector<string>& grid, string& orderedKeys) {
		int lSteps = 0;
		pair<int, int> lStart = mKeys['@'];
		set<char> lPickedKeys;

		grid[lStart.first][lStart.second] = 0;
		for (auto ch = orderedKeys.begin(); ch != orderedKeys.end(); ++ch) {
			cout<<"Step"<<lSteps<<": "<<*ch<<" ("<<lStart.first<<", "<<lStart.second<<")"<<endl;
			int lCurSteps = hBFS(grid, lStart, lPickedKeys, *ch);
			if (lCurSteps == -1) {
				hResetGrid(grid);
				return -1;
			}

			lSteps += lCurSteps;
			lPickedKeys.insert(*ch);
			lStart = mKeys[*ch];
			hResetGrid(grid);
		}

		return lSteps;
	}

	void hResetGrid(vector<string>& grid) {
		for (auto key = mKeys.begin(); key != mKeys.end(); ++key) {
			grid[key->second.first][key->second.second] = key->first;
		}

		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 0) grid[i][j] = '.';
			}
		}

		cout<<"Reset: "<<endl;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	int hBFS(vector<string>& grid, pair<int, int>& start, set<char>& pickedKeys, char target) {
		int lSteps = 0;
		queue<pair<int, int> > lPoints;
		lPoints.push(start);

		cout<<"Target: "<<target<<endl;
		// Try walking around
		while (!lPoints.empty()) {
			int lSize = lPoints.size();
			lSteps++;
			for (int i = 0; i < lSize; ++i) {
				auto lCur = lPoints.front();
				cout<<"BFS Step"<<lSteps<<" ("<<lCur.first<<", "<<lCur.second<<")"<<endl;
				if (hWalkAround(grid, pickedKeys, lCur, lPoints, target) == 1) return lSteps;
				lPoints.pop();
			}
		}

		return -1;
	}

	int hWalkAround(vector<string>& grid, set<char>& pickedKeys, pair<int, int>& cur,
			queue<pair<int, int> >& points, char target) {
		pair<int, int> lNext = cur;
		// Go up
		if (cur.first > 0) {
			lNext.first = cur.first - 1;
			if(hCheckWalkable(grid, pickedKeys, lNext, points, target) == 1) return 1;
		}
		// Go down
		if (cur.first < grid.size() - 1) {
			lNext.first = cur.first + 1;
			if(hCheckWalkable(grid, pickedKeys, lNext, points, target) == 1) return 1;
		}
		lNext = cur;
		// Go left
		if (cur.second > 0) {
			lNext.second = cur.second - 1;
			if(hCheckWalkable(grid, pickedKeys, lNext, points, target) == 1) return 1;
		}
		// Go right
		if (cur.second < grid[0].size() - 1) {
			lNext.second = cur.second + 1;
			cout<<"right: "<<cur.first<<" "<<cur.second<<", "<<lNext.first<<" "<<lNext.second<<" tart: "<<target<<endl;
			cout<<grid[lNext.first][lNext.second]<<endl;
			if(hCheckWalkable(grid, pickedKeys, lNext, points, target) == 1) return 1;
		}

		return -1;
	}
	
	int hCheckWalkable(vector<string>& grid, set<char>& pickedKeys, pair<int, int>& cur,
			queue<pair<int, int> >& points, char target) {
		char ch = grid[cur.first][cur.second];
		if (ch == target) return 1;

		if (ch == '#' || ch == 0) return -1;

		grid[cur.first][cur.second] = 0;
		if ('A' <= ch && ch <= 'F') {
			char lKey = ch - 'A' + 'a';
			if (pickedKeys.find(lKey) == pickedKeys.end()) {
				return -1;
			}
		}

		points.push(cur);
		return -1;
	}

	void hGetKeysLocks(vector<string>& grid, string& keys) {
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				char ch = grid[i][j];
				if (ch == '@' || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F')) {
					if ('a' <= ch && ch <= 'f') keys.push_back(ch);
					mKeys[ch] = make_pair(i, j);
				}
			}
		}
	}

	void hPermutation(string& keys, vector<string>& permutation) {
		if (keys.size() == 1) {
			permutation.push_back(keys);
			return ;
		}

		for (char i = 0; i < keys.size(); i++) {
			char lFirstChar = keys[i];
			string lKeys = keys;

			// Remove the first picked char
			lKeys.erase(i, 1);

			vector<string> lSubPermutation;
			hPermutation(lKeys, lSubPermutation);
			for (auto lSubStrIt = lSubPermutation.begin(); lSubStrIt != lSubPermutation.end(); ++lSubStrIt) {
				string lSubStr(1, lFirstChar);
				lSubStr.append(*lSubStrIt);
				permutation.push_back(lSubStr);
			}
		}
	}
};

int main(int argc, char** argv) {
	//vector<string> grid = {"@.a.#","###.#","b.A.B"};
	//vector<string> grid = {"@..aA","..B#.","....b"};
	//vector<string> grid = {"b","A","a","@","B"};
	vector<string> grid = {"@...a",".###A","b.BCc"};

	Solution lSolution;

	int lSteps = lSolution.shortestPathAllKeys(grid);

	cout<<"Steps: "<<lSteps<<endl;
}
