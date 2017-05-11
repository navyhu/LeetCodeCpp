#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
	int findSteps(string& ring, string& key, int ringIndex, int keyIndex) {
		if (keyIndex == key.size()) return 0;

		char ringChar = ring[ringIndex];
		char keyChar = key[keyIndex];
		cout<<"ring char: "<<ringChar<<", keyChar: "<<keyChar<<", ring index: "<<ringIndex<<", key index: "<<keyIndex<<endl;
		if (ringChar == keyChar) {
			keyIndex++;
			//cout<<"steps:"<<1<<endl;
			return 1 + findSteps(ring, key, ringIndex, keyIndex);
		}

		vector<int> indexes = char2Index[keyChar];
		int idxSize = indexes.size();

		// left is the first index smaller than the current ring index
		// right is the first index bigger than the current ring index
		int left = ringSize;
		int right = ringSize;
		for (int i = 0; i < idxSize; ++i) {
			if (indexes[i] > ringIndex) {
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

		int leftSteps = ringIndex > left ? ringIndex - left : ringIndex + ringSize - left;
		int rightSteps = right > ringIndex ? right - ringIndex : right + ringSize - ringIndex;

		leftSteps++;
		rightSteps++;

		//cout<<"l: "<<left<<", r: "<<right<<", ls: "<<leftSteps<<", rs: "<<rightSteps<<endl;

		keyIndex++;
		int tempLeftSteps = findSteps(ring, key, left, keyIndex);
		leftSteps += tempLeftSteps;
		if (idxSize != 1)
			rightSteps += findSteps(ring, key, right, keyIndex);
		else
			rightSteps += tempLeftSteps;

		return leftSteps < rightSteps ? leftSteps : rightSteps;
	}

	int findRotateSteps(string ring, string key) {
		ringSize = ring.size();

		if (key.size() < 1) return 0;

		for (int i = 0; i < ring.size(); ++i) {
			if (char2Index.find(ring[i]) == char2Index.end()) {
				vector<int> lIndex = {i};
				char2Index[ring[i]] = lIndex;
			} else {
				char2Index[ring[i]].push_back(i);
			}
		}

		/*
		for (auto entry : char2Index) {
			cout<<entry.first<<" : ";
			for (auto idx : entry.second) {
				cout<<idx<<" ";
			}
			cout<<endl;
		}
		*/

		return findSteps(ring, key, 0, 0);
	}

	Solution() : ringSize(0), char2Index() {}

private:
	int ringSize;
	map<char, vector<int>> char2Index;
};

int main() {
	//string ring = "godding";
	//string key = "godding";
	//string key = "gd";
	string ring = "caotmcaataijjxi";
	string key = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";

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
