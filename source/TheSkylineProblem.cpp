#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>

/**
 * By analyzing the requirement, those buildings can be re-shaped to rectangles
 * with no intersection. Those key points are the left-top points of those
 * rectangles, plus the right-bottom points of the last one.
 */
class Solution2
{
public:
	std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings)
	{
		std::vector<std::pair<int, int>> lResult;

		// store the top points on buildings in sorted map
		std::multimap<int, int> lTopPoints;
		for (auto lBuilding : buildings)
		{
			lTopPoints.emplace(lBuilding[0], lBuilding[2]);
			lTopPoints.emplace(lBuilding[1], -lBuilding[2]);
		}

		std::multiset<int> lHeights = { 0 };
		int x = -1;
		int y = 0;
		for (auto lTopPoint : lTopPoints)
		{
			if (x >= 0 && x != lTopPoint.first && (lResult.empty() || lResult.rbegin()->second != y))
			{
				lResult.push_back(std::make_pair(x, y));
			}

			if (lTopPoint.second > 0)
				lHeights.insert(lTopPoint.second);
			else
				lHeights.erase(lHeights.find(-lTopPoint.second));

			x = lTopPoint.first;
			y = *lHeights.rbegin();
		}

		if (!lResult.empty())
			lResult.push_back(std::make_pair(x, 0));

		return lResult;
	}
};

class Solution
{
	public:
		std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>> & buildings)
		{
			std::vector<std::pair<int, int>> lResult;

			if (buildings.size() < 1)
			  return lResult;

			// sort the top points(left-top and right-top) of all buildings
			std::vector<std::vector<int>> lSortedTopPoints;
			for (int lIndex = 0; lIndex < buildings.size(); lIndex++)
			{
				std::vector<int> lBuilding = buildings[lIndex];

				std::vector<int> lTopPoint1 = {lBuilding[0], lBuilding[2], lIndex};
				std::vector<int> lTopPoint2 = {lBuilding[1], lBuilding[2], lIndex};

				lSortedTopPoints.push_back(lTopPoint1);
				lSortedTopPoints.push_back(lTopPoint2);
			}

			std::sort(lSortedTopPoints.begin(), lSortedTopPoints.end());

			/*
			std::cout<<"Sorted Points: ";
			for (auto lPoint : lSortedTopPoints)
			{
				std::cout<<"["<<lPoint[0]<<", "<<lPoint[1]<<", "<<lPoint[2]<<"] ";
			}
			std::cout<<std::endl;
*/

			// find out all possible key points
			std::vector<std::vector<int>> lKeyPoints;
			int lCurrentIndex = 0;
			for (auto lBuilding : buildings)
			{
				std::vector<int> lKeyPoint = {lBuilding[0], lBuilding[2]};
				lKeyPoints.push_back(lKeyPoint);

				lKeyPoint = {lBuilding[1], 0};
				lKeyPoints.push_back(lKeyPoint);

				for (int i = lCurrentIndex; i < lSortedTopPoints.size(); i++)
				{
					std::vector<int> lPoint = lSortedTopPoints[i];

					if (lPoint[0] >= lBuilding[1])
					{
						break;
					}

					if (lPoint[0] > lBuilding[0] && lPoint[1] > lBuilding[2]
								&& lPoint[0] == buildings[lPoint[2]][1])
					{
						lKeyPoint = {lPoint[0], lBuilding[2]};
						lKeyPoints.push_back(lKeyPoint);
						continue;
					}

					if (lPoint[0] == lBuilding[0] && lPoint[1] == lBuilding[2])
					{
						lCurrentIndex = i + 1;
					}
				}
			}

			// sort key points
			std::sort(lKeyPoints.begin(), lKeyPoints.end());

			/*
			std::cout<<"Sorted Key Points: ";
			for (auto lPoint : lKeyPoints)
			{
				std::cout<<"["<<lPoint[0]<<", "<<lPoint[1]<<", "<<lPoint[2]<<"] ";
			}
			std::cout<<std::endl;
*/

			// remove those been covered by buildings
			lCurrentIndex = 0;
			for (auto lBuilding: buildings)
			{
				for (int i = lCurrentIndex; i < lKeyPoints.size(); i++)
				{
					std::vector<int> lPoint = lKeyPoints[i];

					if (lPoint[0] >= lBuilding[1])
					{
						break;
					}

					if (lPoint[0] > lBuilding[0] && lPoint[0] < lBuilding[1] && lPoint[1] < lBuilding[2])
					{
						lKeyPoints.erase(lKeyPoints.begin() + i);
						i--;
						continue;
					}

					if (lPoint[0] <= lBuilding[0])
					{
						lCurrentIndex = i;
					}
				}
			}

			/*
			std::cout<<"Remove covered: ";
			for (auto lPoint : lKeyPoints)
			{
				std::cout<<"["<<lPoint[0]<<", "<<lPoint[1]<<", "<<lPoint[2]<<"] ";
			}
			std::cout<<std::endl;
*/

			// remove those duplicated(or overlapped) key points
			std::vector<int> lKeyPoint = lKeyPoints[0];
			int lLastKeyY = 0;
			for (auto lPoint : lKeyPoints)
			{
				if (lKeyPoint[0] == lPoint[0])
				{
					if (lPoint[1] > lKeyPoint[1])
					{
						lKeyPoint = lPoint;
					}
					continue;
				}

				if (lKeyPoint[1] == lLastKeyY)
				{
					lKeyPoint = lPoint;
					continue;
				}

				std::pair<int, int> lPair = {lKeyPoint[0], lKeyPoint[1]};
				lResult.push_back(lPair);
				lLastKeyY = lKeyPoint[1];
				lKeyPoint = lPoint;
			}
			std::pair<int, int> lPair = {lKeyPoint[0], lKeyPoint[1]};
			lResult.push_back(lPair);

			/*
			std::cout<<"Remove dup: ";
			for (auto lPoint : lKeyPoints)
			{
				std::cout<<"["<<lPoint[0]<<", "<<lPoint[1]<<", "<<lPoint[2]<<"] ";
			}
			std::cout<<std::endl;
*/
			return lResult;
		} // end of function getskyline

};

int main()
{
	const int lBuildingCount = 5;
	const int lCount = 3;
	int lTestInput[][lCount] = 
	/*{
		{1,5,3},
		{1,5,3},
		{1,5,3}
	};*/
	/*{
		{1,2,1},
		{1,2,2},
		{1,2,3}
	};*/
	/*{
		{0,2,3},
		{2,5,3}
	};*/
	{
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};

	std::vector<std::vector<int>> lBuildings;
	for (int i = 0; i < lBuildingCount; i++)
	{
		std::vector<int> lBuilding;
		for (int j = 0; j < lCount; j++)
		{
			lBuilding.push_back(lTestInput[i][j]);
		}

		lBuildings.push_back(lBuilding);
	}

	for (int i = 0; i < lBuildings.size(); i++)
	{
		for (int j = 0; j < lBuildings[i].size(); j++)
		{
		    std::cout<<lBuildings[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	
	Solution2 lTest;
	std::vector<std::pair<int, int>> lResult = lTest.getSkyline(lBuildings);

	for (auto lPoint : lResult)
	{
		std::cout<<"["<<lPoint.first<<", "<<lPoint.second<<"] ";
	}
	std::cout<<std::endl;
}

