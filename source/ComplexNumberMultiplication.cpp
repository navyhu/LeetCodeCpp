#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	void getNumbers(string& num, int& real, int& imag) {
		real = imag = 0;
		bool realNeg = false;
		bool imagNeg = false;

		int state = 0;

		for (auto ch : num) {
			switch (state) {
				case 0:
					if (ch == '-')
						realNeg = true;
					else
						real = ch - '0';
					state = 1;
					break;
				case 1:
					if (ch == '+') {
						state = 2;
						break;
					}
					real = real * 10 + ch - '0';
					break;
				case 2:
					if (ch == '-')
						imagNeg = true;
					else
						imag = ch - '0';
					state = 3;
					break;
				case 3:
					if (ch == 'i') {
						state = 4;
						break;
					}
					imag = imag * 10 + ch - '0';
					break;
				default:
					break;
			}

			if (state == 4)
				break;
		}

		real = realNeg ? -real : real;
		imag = imagNeg ? -imag : imag;
	}

	string num2String(int num) {
		string result;
		if (num == 0) {
			result.push_back('0');
			return result;
		}
		else if (num < 0) {
			result.push_back('-');
			num = -num;
		}

		vector<int> digits;
		while (num) {
			digits.push_back(num % 10);
			num /= 10;
		}

		for (auto digit = digits.rbegin(); digit != digits.rend(); ++digit) {
			result.push_back('0' + *digit);
		}

		return result;
	}

	string constructComplexNumber(int real, int imag) {
		string num;
		num.insert(num.size(), num2String(real));

		num.push_back('+');

		num.insert(num.size(), num2String(imag));

		num.push_back('i');

		return num;
	}

	string complexNumberMultiply(string a, string b) {
		int aReal = 0, aImag = 0, bReal = 0, bImag = 0;

		getNumbers(a, aReal, aImag);
		getNumbers(b, bReal, bImag);

		int real = aReal * bReal - aImag * bImag;
		int imag = aReal * bImag + bReal * aImag;

		return constructComplexNumber(real, imag);
	}
};

int main() {
	string a = "78+8i";
	string b = "2+-3i";
	Solution test;

	string result = test.complexNumberMultiply(a, b);
	cout<<a<<endl<<b<<endl<<result<<endl;
	return 0;
}
