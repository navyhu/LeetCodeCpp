#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

class Solution {
public:
	string checkIPv4(string IP) {
		if (IP[0] == '.') return "Neither";
		int state = 1;
		int num = 0;
		int digitCnt = 0;
		for (auto ch : IP) {
			if (ch == '.') {
				if (state > 4 || digitCnt == 0) return "Neither";
				num = 0;
				digitCnt = 0;
				++state;
			} else if (ch < '0' || ch > '9') {
				return "Neither";
			} else {
				if (digitCnt > 0 && num == 0 ) return "Neither";
				num = num * 10 + ch - '0';
				if (num > 255) return "Neither";
				++digitCnt;
			}
		}

		if (state == 4 && digitCnt) return "IPv4";

		return "Neither";
	}

	string checkIPv6(string IP) {
		if (IP[0] == ':') return "Neither";
		int state = 1;
		int digitCnt = 0;

		for (auto ch : IP) {
			auto upper = toupper(ch);
			if (ch == ':') {
				if (state > 8 || digitCnt == 0) return "Neither";
				digitCnt = 0;
				++state;
			} else if (('0' <= upper && upper <= '9') || ('A' <= upper && upper <= 'F')) {
				if (digitCnt >= 4) return "Neither";
				digitCnt++;
			} else {
				return "Eeither";
			}
		}

		if (state == 8 && digitCnt) return "IPv6";

		return "Neither";
	}

	string validIPAddress(string IP) {
		if (IP.size() > 39) return "Neither";

		if (IP.find_first_of('.') != string::npos)
			return checkIPv4(IP);
		else if (IP.find_first_of(':') != string::npos)
			return checkIPv6(IP);

		return "Neither";
	}
};

int main() {
	string IP = "256.256.256.256";//"2001:0db8:85a3:0:0:8A2E:0370:7334";//"172.16.254.1";
	Solution test;

	string result = test.validIPAddress(IP);

	cout<<IP<<endl<<result<<endl;
	return 0;
}
