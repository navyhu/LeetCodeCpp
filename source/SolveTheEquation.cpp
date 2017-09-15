#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
	string solveEquation(string equation) {
		bool left = true;
		int coeX = 0;
		int cons = 0;
		int tmp = 0;
		bool minus = false;
		bool hasDigit = false;

		for (auto& ch : equation) {
			switch (ch) {
				case '-':
				case '+':
				case '=':
					if (tmp) {
						if (minus && left) tmp = -tmp;
						if (!minus && !left) tmp = -tmp;
						cons -= tmp;
						tmp = 0;
					}
					minus = false;
					hasDigit = false;
					if (ch == '-') minus = true;
					else if (ch == '=') left = false;
					break;
				case 'x':
					if (tmp == 0 && !hasDigit) tmp = 1;
					if (minus && left) tmp = -tmp;
					if (!minus && !left) tmp = -tmp;
					coeX += tmp;
					tmp = 0;
					hasDigit = false;
					break;
				default:
					hasDigit = true;
					tmp = tmp * 10 + (ch - '0');
					break;
			}
		}

		if (tmp) {
			if (minus && left) tmp = -tmp;
			if (!minus && !left) tmp = -tmp;
			cons -= tmp;
		}

		if (cons == 0 && coeX == 0) return "Infinite solutions";
		if (coeX == 0) return "No solution";

		string result("x=");
		return result + to_string(cons/coeX);
	}
};

int main() {
	Solution test;
	//string equation = "x+5-3+x=6+x-2";
	//string equation = "2x+3x-6x=x+2";
	//string equation = "x=x+1";
	string equation = "0x=0";

	cout<<equation<<endl;
	cout<<test.solveEquation(equation)<<endl;

	return 0;
}
