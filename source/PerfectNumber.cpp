#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

class Solution {
public:
	void getAllDivisors(int num, set<int>& divisors) {
		if (primes.find(num) != primes.end()) return;

		// find the biggest divisor which is not bigger than its root
		int biggest = sqrt(num);
		while (num % biggest) --biggest;

		if (biggest == 1) return;

		divisors.insert(biggest);
		divisors.insert(num / biggest);

		set<int> subDivisors;
		getAllDivisors(biggest, subDivisors);
		if (biggest != num / biggest) getAllDivisors(num / biggest, subDivisors);

		for (auto divisor : subDivisors) {
			divisors.insert(divisor);
			divisors.insert(num / divisor);
		}
	}

	bool checkPerfectNumber(int num) {
		if (num < 6) return false;

		primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

		set<int> divisors;
		getAllDivisors(num, divisors);

		if(num == accumulate(divisors.begin(), divisors.end(), 1)) return true;

		return false;
	}

	set<int> primes;
};

int main() {
	Solution test;

	int num = 496;//8128;//496;

	bool result = test.checkPerfectNumber(num);

	cout<<num<<endl<<result<<endl;

	return 0;
}
