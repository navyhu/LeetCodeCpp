#include <iostream>
#include <math.h>
#include <vector>

class Solution {
	public:
		int maximumSwap(int num) {
			if (num < 12) return num;

			int lTmpNum = num;

			std::vector<int> lDigits;

			while (lTmpNum) {
				lDigits.push_back(lTmpNum % 10);
				lTmpNum = lTmpNum / 10;
			}

			for (int i = lDigits.size() - 1; i > 0; i--) {
				int lMaxVal = lDigits[i];
				int lMaxIdx = i;
				for (int j = i - 1; j >= 0; j--) {
					if (lMaxVal <= lDigits[j]) {
						lMaxVal = lDigits[j];
						lMaxIdx = j;
					}
				}

				if (lMaxVal > lDigits[i])
					return num + (lDigits[lMaxIdx] - lDigits[i]) * pow(10, i) - (lDigits[lMaxIdx] - lDigits[i]) * pow(10, lMaxIdx);
			}

			return num;
		}
};

int main() {
	Solution test;

	int lNum = 2;
	std::cout<<lNum<< ":" <<test.maximumSwap(lNum)<<std::endl;

	lNum = 7890;
	std::cout<<lNum<< ":" <<test.maximumSwap(lNum)<<std::endl;

	lNum = 9987;
	std::cout<<lNum<< ":" <<test.maximumSwap(lNum)<<std::endl;

	lNum = 98377289;
	std::cout<<lNum<< ":" <<test.maximumSwap(lNum)<<std::endl;

	lNum = 983772;
	std::cout<<lNum<< ":" <<test.maximumSwap(lNum)<<std::endl;

	lNum = 2736;
	std::cout<<lNum<< ":" <<test.maximumSwap(lNum)<<std::endl;
	return 0;
}
