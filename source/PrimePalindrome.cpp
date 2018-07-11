#include <iostream>
#include <math.h>

class Solution {
public:
    int primePalindrome(int N) {
		if (N <= 2) return 2;
		if (N == 3) return 3;
		if (N <= 5) return 5;
		if (N <= 7) return 7;
		if (N <= 11) return 11;

		if (!hIsPalindrome(N))
			N = hNextPalindrome(N);

		while (!hIsPrime(N)) {
			N = hNextPalindrome(N);
		}

		std::cout<<"Prime Palindrome: "<<N<<std::endl;

		return N;
    }

private:
	bool hIsPalindrome(int N) {
		int lDigits[20];
		int lCount = 0;
		int lTmp = N;
		while (lTmp) {
			lDigits[lCount] = lTmp % 10;
			lTmp /= 10;
			lCount++;
		}

		for (int i = 0; i < lCount / 2; i++) {
			if (lDigits[i] != lDigits[lCount - 1 - i])
				return false;
		}

		return true;
	}

	int hNextPalindrome(int N) {
		// Loop until got a valid palindrome and prime candidate
		// Use while instead of recursive call to get better performance
		while (true) {
			// Assume N > 11
			int lDigits[20];
			int lCount = 0;
			int lTmp = N;
			while (lTmp) {
				lDigits[lCount] = lTmp % 10;
				lTmp /= 10;
				lCount++;
			}

			// Get first half number
			// 1234 -> 12 -> 13 -> 1331
			// 12345 -> 123 -> 124 -> 12421
			int lLeftCount = lCount - ((lCount + 1) / 2);
			int lFirstHalf = N;
			for (int i = 0; i < lCount / 2; i++) {
				lFirstHalf /= 10;
			}

			lFirstHalf++;	// Next palindrome number
			lCount = 0;
			while (lFirstHalf) {
				lDigits[lCount] = lFirstHalf % 10;
				lFirstHalf /= 10;
				lCount++;
			}

			// Simple checks for non-prime number
			int lFirstDigIdx = lCount - 1;
			if (lDigits[lFirstDigIdx] == 2 || lDigits[lFirstDigIdx] == 6 || lDigits[lFirstDigIdx] == 8)
				lDigits[lFirstDigIdx] = lDigits[lFirstDigIdx] + 1;;
			if (lDigits[lFirstDigIdx] == 4 || lDigits[lFirstDigIdx] == 5)
				lDigits[lFirstDigIdx] = 7;

			// Get new palindrome
			int lCheckDivBy3 = 0;
			N = 0;
			for (int i = 0; i < lLeftCount + lCount; i++) {
				int lCurDig = 0;
				if (i < lLeftCount) {
					lCurDig = lDigits[lCount - 1 - i];
				} else {
					lCurDig = lDigits[i - lLeftCount];
				}
				N = N * 10 + lCurDig;
				lCheckDivBy3 += lCurDig;
			}

			// It's not prime number if it can be exactly divided by 3
			// Continue finding next one
			if (lCheckDivBy3 % 3 == 0)
				continue;

			//std::cout<<N<<std::endl;
			return N;
		}
	}

	bool hIsPrime(int N) {
		int lSqrt = sqrt(N);

		// Start from 7, as we've excluded 2, 3, 4, 5, 6
		for (int i = 7; i <= lSqrt + 1; i += 2) {
			if (N % i == 0)
				return false;
		}

		return true;
	}
};

int main(int arg, char** argv) {
	Solution lSolution;

	int N = 20;
	for (int i = 0; i < 100; i++) {
		N = lSolution.primePalindrome(N);
		N += 100;
	}
}
