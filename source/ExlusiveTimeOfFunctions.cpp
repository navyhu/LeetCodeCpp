#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

class Solution {
	public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> result(n, 0);
		if (n == 0) return result;

		stack<vector<int>> functions;
		for (auto& log : logs) {
			int function = 0;
			bool start = true;
			int time = 0;
			int recursive = 0;
			getInfo(log, function, start, time);

			if (start) {
				vector<int> func = {function, time, 0};
				functions.push(func);
			} else {
				auto& startFunc = functions.top();
				int totalTime = time - startFunc[1] + 1;
				result[startFunc[0]] += totalTime - startFunc[2];
				functions.pop();

				if (!functions.empty()) {
					auto& upperFunc = functions.top();
					upperFunc[2] = upperFunc[2] + totalTime;
				}
			}
		}

		return result;
	}

	void getInfo(string& log, int& function, bool& start, int& time) {
		int state = 0;

		for (int i = 0; i < log.size(); i++) {
			if (log[i] == ':') {
				state++;
			} else if (state == 0) {
				function = function * 10 + (log[i] - '0');
			} else if (state == 1) {
				if (log[i] == 's') {
					start = true;
					i += 5;
				} else {
					start = false;
					i += 3;
				}
				state = 2;
			} else if (state == 2) {
				time = time * 10 + (log[i] - '0');
			}
		}
	}
};

int main() {
	Solution test;

	vector<string> logs = 
	{
		"0:start:0",
		"1:start:2",
		"2:start:3",
		"2:end:5",
		"1:end:7",
		"3:start:9",
		"4:start:12",
		"4:end:15",
		"3:end:16",
		"0:end:18"
	};

	for (auto& log : logs) {
		cout<<log<<endl;
	}

	vector<int> result = test.exclusiveTime(logs.size() / 2, logs);

	for (auto& res : result) {
		cout<<res<<endl;
	}

	return 0;
}
