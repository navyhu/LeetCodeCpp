
class Solution {
	public:
		int minSteps(int n) {
			if (n == 1) return 0;
			int a = static_cast<int>(sqrt(n));
			int b = 1;
			int steps = 1002;

			for (a; a > 0; a--) {
				if (n % a == 0) {
					b = n / a;
					int total = b;
					if (a != 1)
						total = a + minSteps(b);

					steps = steps < total ? steps : total;
				}
			}

			return steps;
		}
};
