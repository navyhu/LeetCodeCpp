
class Solution {
	public:
		string predictPartyVictory(string senate) {
			return predictPartyVictory(senate, 0, 0);
		}

		string predictPartyVictory(string senate, int banD, int banR) {
			string remain;
			int countD = 0;
			int countR = 0;
			for (auto ch = senate.begin(); ch != senate.end(); ++ch) {
				if (*ch == 'D') {
					if (banD == 0) {
						banR++;
						remain.push_back(*ch);
					} else {
						banD--;
					}
					countD++;
				} else {
					if (banR == 0) {
						banD++;
						remain.push_back(*ch);
					} else {
						banR--;
					}
					countR++;
				}
			}

			if (countD == 0) return "Radiant";
			if (countR == 0) return "Dire";

			return predictPartyVictory(remain, banD, banR);
		}
};
