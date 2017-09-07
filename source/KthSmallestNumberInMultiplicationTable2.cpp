

/**
  Use binary search, start from lower-value = 1 and upper-value = m * n, take the mid-value,
  check if there are at least k value smaller than the mid-value. If yes, the target should
  be smaller or equal to this mid-value, set the upper-value to the mid-value, run another
  round. If no, the target should be greater than this mid-value, set the lower-value to
  mid-value + 1, run another round. When the lower and upper values are met, the target is found.
  */
class Solution {
	public:
		int findKthNumber(int m, int n, int k) {
			int lLower = 1;
			int lUpper = m * n;

			while (lLower < lUpper) {
				int lMid = (lLower + lUpper) / 2;
				if (smallerCount(lMid, m, n) >= k)
					lUpper = lMid;
				else
					lLower = lMid + 1;
			}

			return lLower;
		}

		int smallerCount(int val, int m, int n) {
			int lCount = 0;
			for (int i = 1; i <= m; i++) {
				lCount += std::min(val / i, n);
			}
			return lCount;
		}
}
