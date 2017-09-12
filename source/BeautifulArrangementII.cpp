#include <iostream>
#include <vector>

class Solution {
	public:
		std::vector<int> constructArray(int n, int k) {
			std::vector<int> result;

			for (int i = 1; i <= n; i++)
				result.push_back(i);

			for (int i = 0; i <= k; i++) {
				if (i % 2) {
					result[i] = k + 1 - i / 2;
				} else {
					result[i] = i / 2 + 1;
				}
			}

			std::cout<<"(";
			for (auto it = result.begin(); it != result.end(); ++it) {
				std::cout<<*it<<", ";
			}
			std::cout<<")"<<std::endl;

			return result;
		}
};

int main() {
	Solution test;

	test.constructArray(9, 5);

	return 0;
}
