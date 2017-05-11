#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
	pair<pair<int, int>, pair<int, int>> getMoves(string& ring, pair<char, int> keyCharRingIdx) {
		if (lrMoves.find(keyCharRingIdx) != lrMoves.end())
			return lrMoves[keyCharRingIdx];

		char keyChar = keyCharRingIdx.first;
		int ringIdx = keyCharRingIdx.second;

		vector<int> indexes = ringChar2Indices[keyChar];

		if (ring[ringIdx] == keyChar) {
			return make_pair(make_pair(1, ringIdx), make_pair(1, ringIdx));
		}

		int idxSize = indexes.size();

		// left is the first index smaller than the current ring index
		// right is the first index bigger than the current ring index
		int left = ringSize;
		int right = ringSize;
		for (int i = 0; i < idxSize; ++i) {
			if (indexes[i] > ringIdx) {
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

		int leftSteps = 1 + (ringIdx > left ? ringIdx - left : ringIdx + ringSize - left);
		int rightSteps = 1 + (right > ringIdx ? right - ringIdx : right + ringSize - ringIdx);

		return make_pair(make_pair(leftSteps, left), make_pair(rightSteps, right));
	}

	void updateMoves(string& ring, char keyChar) {
		pair<int, int> curLeastMove = {0, 0};
		auto move = moves.begin();
		while (move != moves.end()) {
			int Steps2Least = move->second - leastMoveIndex.second;
			Steps2Least = Steps2Least > 0 ? Steps2Least : -Steps2Least;
			Steps2Least = 1 + (Steps2Least < ringSize - Steps2Least ? Steps2Least : ringSize - Steps2Least);

			if (move->first - leastMoveIndex.first >= Steps2Least) {
				move = moves.erase(move);
				continue;
			}

			auto nextMoves = getMoves(ring, make_pair(keyChar, move->second));

			cout<<"next moves: ("<<nextMoves.first.first<<", "<<nextMoves.first.second<<") ";
			cout<<"("<<nextMoves.second.first<<", "<<nextMoves.second.second<<")"<<endl;;

			if (nextMoves.first.second != nextMoves.second.second) {
				pair<int, int> newMove = {move->first + nextMoves.second.first, nextMoves.second.second};
				moves.insert(move, newMove);
				cout<<"new move: "<<newMove.first<<", "<<newMove.second<<endl;

				if (curLeastMove.first == 0) {
					curLeastMove = newMove;
				} else if (newMove.first < curLeastMove.first) {
					curLeastMove.first = newMove.first;
					curLeastMove.second = newMove.second;
				}
			} else if (nextMoves.second.first < nextMoves.first.first) {
				nextMoves.first.first = nextMoves.second.first;
			}

			move->first += nextMoves.first.first;
			move->second = nextMoves.first.second;
			cout<<"move: "<<move->first<<", "<<move->second<<endl;
			if (curLeastMove.first == 0) {
				curLeastMove = *move;
			} else if (move->first < curLeastMove.first) {
				curLeastMove.first = move->first;
				curLeastMove.second = move->second;
			}

			cout<<"cur least move: "<<curLeastMove.first<<", "<<curLeastMove.second<<endl;

			++move;
		}

		leastMoveIndex = curLeastMove;
	}

	void debugPrint() {
		cout<<"****************";
		cout<<"size: "<<ringSize<<", "<<keySize<<endl;
		cout<<"least move index: "<<leastMoveIndex.first<<", "<<leastMoveIndex.second<<endl;
		cout<<"moves:"<<endl;
		for (auto move : moves) {
			cout<<"("<<move.first<<", "<<move.second<<") ";
		}
		cout<<endl;

		cout<<"lrMoves:"<<endl;
		for (auto lrMove: lrMoves) {
			cout<<"("<<lrMove.first.first<<", "<<lrMove.first.second<<"): ";
			cout<<"("<<lrMove.second.first.first<<", "<<lrMove.second.first.second<<") ";
			cout<<"("<<lrMove.second.second.first<<", "<<lrMove.second.second.second<<") "<<endl;;
		}
		cout<<endl;
		map<pair<char, int>, pair<pair<int, int>, pair<int, int>>> lrMoves;
	}

	int findRotateSteps(string ring, string key) {
		ringSize = ring.size();
		keySize = key.size();

		for (int i = 0; i < ringSize; ++i) {
			if (ringChar2Indices.find(ring[i]) == ringChar2Indices.end()) {
				vector<int> indices = {i};
				ringChar2Indices[ring[i]] = indices;
			} else {
				ringChar2Indices[ring[i]].push_back(i);
			}
		}

		// the first move
		leastMoveIndex.first = ringSize + 1;
		leastMoveIndex.second = 0;
		moves.push_back(make_pair(0, 0));

		for (auto keyChar : key) {
			debugPrint();
			updateMoves(ring, keyChar);
		}
		debugPrint();

		return leastMoveIndex.first;
	}

	Solution():
		ringSize(0), keySize(0), leastMoveIndex(),
		ringChar2Indices(), moves(), lrMoves()
	{}

private:
	int ringSize;
	int keySize;
	// ring char to indexes(there might be sames chars in ring) map
	map<char, vector<int>> ringChar2Indices;
	// the least move count and corresponding index
	pair<int, int> leastMoveIndex;
	// moves(and corresponding indices) for each choice
	list<pair<int, int>> moves;
	// key: pair<key char, ring index>
	// value: pair<pair<left least move, ring index>, pair<right least move, ring index>>
	map<pair<char, int>, pair<pair<int, int>, pair<int, int>>> lrMoves;
};

void getMovesTest() {
	string ring = "abcdefgaadgcbe";
	string key = "adfcaabge";

	vector<int> indexes = {1, 3, 0, 2, 3, 8, 9, 7, 6};

	Solution test;

	test.findRotateSteps(ring, key);

	for (int i = 0; i < indexes.size(); ++i) {
		auto result = test.getMoves(ring, make_pair(key[i], indexes[i]));

		cout<<"key index: "<<key[i]<<", "<<indexes[i]<<endl;
		cout<<"result: ("<<result.first.first<<", "<<result.first.second<<"), (";
		cout<<result.second.first<<", "<<result.second.second<<")"<<endl;;
	}
}

void test() {
	string ring = "godding";
	//string key = "godding";
	string key = "gd";

	//string ring = "caotmcaataijjxi";
	//string key = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";
	cout<<ring<<endl;
	cout<<key<<endl;

	Solution test;

	cout<<test.findRotateSteps(ring, key)<<endl;
}

int main() {

	//getMovesTest();

	test();

	return 0;
}
