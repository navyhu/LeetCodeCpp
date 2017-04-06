
class Solution {
	public:
		int findComplement(int num) {
			int mask = 0xFFFFFFFF;

			while (mask & num) {
				mask = mask << 1;
			}

			return mask ^ (~num);
		}
};
