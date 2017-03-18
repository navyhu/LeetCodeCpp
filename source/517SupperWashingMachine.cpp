#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& nums) {
	for (auto num : nums) {
		cout<<num<<" ";
	}
	cout<<endl;
}

class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		int size = machines.size();
		if (size < 2)
			return 0;

		int sum = 0;
		for (auto machine : machines) {
			sum += machine;
		}

		if (sum % size != 0)
			return -1;

		int avg = sum / size;
		int start = 0;
		int move = 0;
		while (start < size) {
			if (machines[start] == avg) {
				start++;
				continue;
			}

			//print(machines);
			move++;
			int delta = 0;
			int lastMoveOutIndex = -1;
			for (int i = start; i < size - 1; ++i) {
				cout<<"Before move:";
				print(machines);
				delta += machines[i] - avg;
				cout<<delta<<" : "<<machines[i]<<" (i = "<<i<<")"<<endl;
				if (delta > 0 && machines[i] > 0 && i != lastMoveOutIndex) {
					machines[i]--;
					machines[i + 1]++;
					delta--;
				} else if (delta < 0 && machines[i + 1] > 0) {
					machines[i]++;
					machines[i + 1]--;
					delta++;
					lastMoveOutIndex = i + 1;
				}
				print(machines);
			}
			print(machines);
		}

		return move;
	}
};

class Solution2 {
public:
	int findMinMoves(vector<int>& machines) {
		int size = machines.size();
		if (size < 2)
			return 0;

		int sum = 0;
		for (auto machine : machines) {
			sum += machine;
		}

		if (sum % size != 0)
			return -1;

		int avg = sum / size;
		int delta = 0;
		int move = 0;
		for (int& machine : machines) {
			int lMove = machine - avg;
			delta += lMove;

			int lDelta = delta > 0 ? delta : -delta;

			move = lDelta > move ? lDelta : move;

			if (lMove > 0)
				move = lMove > move ? lMove : move;
		}

		return move;
	}
};

int main() {
	//vector<int> machines = {1, 0, 5, 2, 4, 6};
	//vector<int> machines = {1, 0, 5};
	//vector<int> machines = {0, 3, 0};
	//vector<int> machines = {4, 0, 0, 4};
	vector<int> machines = {9, 1, 8, 8, 9};

	print(machines);

	Solution2 lTest;
	int move = lTest.findMinMoves(machines);
	cout<<"Move: "<<move<<endl;

	return 0;
}
