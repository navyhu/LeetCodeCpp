#include <iostream>
#include <string>

class Solution
{
public:
	std::string reverseStr(std::string s, int k)
	{
		if (k < 2)
			return s;

		int k2 = 2*k;
		int size = s.size();

		k--;
		int left = 0;
		int right = left + k;
		int nextLeft = left + k2;

		while (left < size)
		{
			if (right >= size)
				right = size - 1;

			while (left < right)
			{
				std::swap(s[left], s[right]);
				left++;
				right--;
			}

			left = nextLeft;
			right = left + k;
			nextLeft = left + k2;
		}

		return s;
	}
};

int main()
{
	std::string lString = "abcdefghijklmn";
	int k = 3;

	std::cout<<lString<<std::endl;

	Solution lTest;
	std::string lResult = lTest.reverseStr(lString, k);

	std::cout<<lResult<<std::endl;
}
