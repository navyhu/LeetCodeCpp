#include <iostrea>

using namespace std;

class Solution {
	public:
	bool judgeSquareSum(int c) {
		int root = sqrt(c);

		for (int i = 0; i <= root; i++) {
			int tmp = c - i * i;
			int tmp_root = sqrt(tmp);
			if (tmp == tmp_root * tmp_root) return true;
		}

		return false;
	}
};
