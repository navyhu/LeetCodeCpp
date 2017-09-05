#include <iostream>

/*
   Treat the bulbs as a number 'Num' with binary view. The buttons are just other numbers with binary view.
   Clicking a button means to apply a XOR on the 'Num' and the number for a specific button.
   With such observation, we can figure out some special cases, and except those special case, the number of
   state is always 8.
*/

class Solution {
	public:
		int flipLights(int n, int m) {
			if (n == 0) return 0;
			if (m == 0) return 1;

			if (n == 1) return 2; // for any m > 0

			if (n == 2) {
				if (m == 1) return 3;
				return 4;
			}

			// for n > 2
			if (m == 1) return 4;
			if (m == 2) return 7;
			
			return 8;
		}
};
