#include <iostream>
#include <string>
#include <vector>
#include <set>

class Solution
{
public:
	int findMinDifference(std::vector<std::string>& timePoints)
	{
		int lResult = 24*60;
		std::set<int> lMinutesSet;

		for (auto time : timePoints)
		{
			int lMinutes = (time[0] - '0')*600 + (time[1] - '0')*60 + (time[3] - '0')*10 + time[4] - '0';
			lMinutesSet.insert(lMinutes);
		}

		if (timePoints.size() != lMinutesSet.size())
		    return 0;

		typedef std::set<int>::iterator setIt;
		setIt lPre = lMinutesSet.begin();
		setIt lCur = lMinutesSet.begin();
		lCur++;

		for (lCur; lCur != lMinutesSet.end(); lCur++)
		{
			int diff = *lCur - *lPre;
			if (diff < lResult)
			    lResult = diff;

			lPre = lCur;
		}

		int diff = 24*60 + *lMinutesSet.begin() - *lMinutesSet.rbegin();

		return (diff < lResult) ? diff : lResult;
	}
};

int main()
{
	std::vector<std::string> lTimePoints = {"22:54", "21:45", "00:43", "00:01", "23:50"};

	Solution lTest;
	std::cout<<lTest.findMinDifference(lTimePoints)<<std::endl;
}
