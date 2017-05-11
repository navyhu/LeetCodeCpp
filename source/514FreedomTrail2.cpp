#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>

using namespace std;

class Solution {
public:
	pair<pair<int, int>, pair<int, int>> getMoves(string& ring, pair<int, char>& idx2char) {
		if (movesMap.find(idx2char) != movesMap.end())
			return movesMap[idx2char];

		// calculate the left and right least moves
		vector<int> indexes = char2Index[idx2char.second];
		int idxSize = indexes.size();

		// left is the first index smaller than the current ring index
		// right is the first index bigger than the current ring index
		int left = ringSize;
		int right = ringSize;
		for (int i = 0; i < idxSize; ++i) {
			if (indexes[i] > idx2char.first) {
				right = indexes[i];
				if (i > 0)
					left = indexes[i - 1];
				else
					left = indexes[idxSize - 1];
				break;
			}
		}

		if (right == ringSize) {
			left = indexes[idxSize - 1];
			right = indexes[0];
		}

		int leftSteps = idx2char.first > left ? idx2char.first - left : idx2char.first + ringSize - left;
		int rightSteps = right > idx2char.first ? right - idx2char.first : right + ringSize - idx2char.first;

		leftSteps++;
		rightSteps++;

		auto movesPair = make_pair(make_pair(leftSteps, left), make_pair(rightSteps, right));
		movesMap[idx2char] = movesPair;

		return movesPair;
	}

	void updateMoves(string& ring, char keyCh) {
		auto idxMove = Idx_Move.begin();
		while (idxMove != Idx_Move.end()) {
			// compair with the current least move
			int distance = idxMove->first - leastIdx;
			distance = distance > 0 ? distance : -distance;
			distance = keySize - distance < distance ? keySize - distance : distance;
			if (idxMove->second - leastMove >= distance) {
				idxMove = Idx_Move.erase(idxMove);
				continue;
			}

			// get left, right move steps
			pair<int, int> lrMoves = getMoves(ring, make_pair(idxMove->first, keyCh));
			if (char2Index[keyCh].size() == 1) {
				// only move one direction
				int moves = lrMoves.first < lrMoves.second ? lrMoves.first : lrMoves.second;

			}
		}
	}

	int findRotateSteps(string ring, string key) {
		ringSize = ring.size();

		for (int i = 0; i < ringSize; ++i) {
			if (char2Index.find(ring[i]) == char2Index.end()) {
				vector<int> indexes = {i};
				char2Index[ring[i]] = indexes;
			} else {
				char2Index[ring[i]].insert(i);
			}
		}

		int leastIdx = 0;
		int leastMove = 0;
		Idx_Move.insert(make_pair(leastIdx, leastMove));

		for (char keyCh : key) {
			auto idxMove = Idx_Move.begin();
			while (idxMove != Idx_Move.end()) {
				
			}
		}
	}

	Solution() : leastIdx(0), leastMove(0), ringSize(0), keySize(0), char2Index(), Idx_Move(), movesMap() {}

	int leastIdx;
	int leastMove;
	int ringSize;
	int keySize;
	map<char, vector<int>> char2Index;
	list<pair<int, int>> Idx_Move;
	// key: <ring index, key char>
	// value: <<left least move, index>, <right least move, index>>
	map<pair<int, char>, pair<pair<int, int>, pair<int, int>>> movesMap;
};

void getMovesTest() {
	Solution test;

	string ring = "abcdefg";
	string key = "acdeegac";

	vector<int> index = {2, 0, 4, 6, 2, 0};

	for (int i = 0; i < index.size(); ++i) {
		auto result = test.getMoves(ring, make_pair(key[i], index[i]));

		cout<<"Key Index: "<<key[i]<<", "<<index[i]<<endl;
		cout<<"pair: ("<<result.first.first<<", "<<result.first.second<<"), (";
		cout<<result.second.first<<", "<<result.second.second<<")";
	}
}

int main() {
	//string ring = "godding";
	//string key = "godding";
	//string key = "gd";
	string ring = "caotmcaataijjxi";
	string key = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";

	getMovesTest();
	return 0;

	/*set<int> test = {1, 3, 5, 6, 9};
	cout<<*test.lower_bound(7)<<endl;
	cout<<*test.upper_bound(2)<<endl;
	return 1;
*/
	cout<<"ring: "<<ring<<endl;
	cout<<"key: "<<key<<endl;

	Solution lTest;

	int steps = lTest.findRotateSteps(ring, key);

	cout<<"steps: "<<steps<<endl;
	return 0;
}
