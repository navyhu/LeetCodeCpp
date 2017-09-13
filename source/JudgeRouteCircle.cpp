#include <iostream>

class Solution {
	public:
		bool judgeCircle(string moves) {
			int ver = 0;
			int hor = 0;

			for (auto it = moves.begin(); it != moves.end(); ++it) {
				switch(*it) {
					case 'U':
						ver++;
						break;
					case 'D':
						ver--;
						break;
					case 'L':
						hor++;
						break;
					case 'R':
						hor--;
						break;
				}
			}

			if (ver == 0 && hor == 0) return true;

			return false;
		}
};
