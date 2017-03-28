#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> constructRectangle(int area) {
		int sqrtValue = sqrt(area);

		while (area % sqrtValue != 0)
			sqrtValue--;

		int L = area / sqrtValue;

		if (L > sqrtValue) return {L, sqrtValue};

		return {sqrtValue, L};
	}
};


int main() {
	int area = 5;

	Solution test;
	vector<int> result = test.constructRectangle(area);

	cout<<"result: "<<result[0]<<" "<<result[1]<<endl;

	return 0;
}
