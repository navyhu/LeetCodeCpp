#include <iostream>
#include <vector>
#include <set>
#include <map>

class Solution
{
public:
	int findPairs(std::vector<int>& nums, int k)
	{
		if (nums.size() < 2 || k < 0)
		  return 0;

		int lResult = 0;
		std::map<int, int> lMap;
		for (auto lNum : nums)
		{
			if (lMap.find(lNum) != lMap.end())
				lMap[lNum] = 2;
			else
				lMap[lNum] = 1;
		}

		if (k == 0)
		{
			for (auto lEntry : lMap)
			{
				if (lEntry.second == 2)
				    lResult++;
			}
		}
		else
		{
			for (auto lEntry : lMap)
			{
				if (lMap.find(lEntry.first + k) != lMap.end())
				    lResult++;
			}
		}

		return lResult;
	}
};

int main()
{
	std::vector<int> lNums = {1, 2, 2, 2, 1, 3, 4, 9, 10};

	for (auto lNum : lNums)
	    std::cout<<lNum<<" ";
	std:: cout<<std::endl;;

	Solution lTest;
	std::cout<<lTest.findPairs(lNums, 0)<<std::endl;
}
