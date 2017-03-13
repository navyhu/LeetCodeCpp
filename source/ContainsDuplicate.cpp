#include <iostream>
#include <vector>
#include <set>

class Solution
{
public:
	bool containsDuplicate(std::vector<int>& nums)
	{
		std::set<int> lSet;
		int lPreSize = -1;
		for (auto lNum : nums)
		{
			lPreSize = lSet.size();
			lSet.insert(lNum);

			if (lPreSize == lSet.size())
			  return true;
		}

		return false;
	}

	bool containsDuplicate2(std::vector<int>& nums)
	{
		std::unordered_set<int> lSet;
		int lPreSize = -1;
		for (auto lNum : nums)
		{
			lPreSize = lSet.size();
			lSet.insert(lNum);

			if (lPreSize == lSet.size())
			  return true;
		}

		return false;
	}
};

int main()
{
	std::vector<int> lNums = {1, 2, 4, 5, 2, 6, 7};

	Solution lTest;
	std::cout<<"Contains: "<<lTest.containsDuplicate(lNums)<<std::endl;

	return 0;
}
