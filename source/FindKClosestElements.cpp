#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> findClosestElements(vector<int>& arr, int k, int x) {
			// find position of x(or the nearest smaller one)
			int lIdx = arr.size();

			cout<<"start: "<<k<<", "<<x<<endl;

			for (int i = 0; i < arr.size(); i++) {
				if (x <= arr[i]) {
					lIdx = x == arr[i] ? i : i - 1;
					break;
				}
			}

			int lStart = lIdx;
			int lEnd= lIdx + 1;
			int lStartIdx = lStart;
			for (int i = 0; i < k; i++) {
				if (lStart < 0) {
					lStartIdx = 0;
					break;
				} else if (lEnd >= arr.size()) {
					lStartIdx = arr.size() - k;
					break;
				}
				if (x - arr[lStart] <= arr[lEnd] - x) {
					lStartIdx = lStart;
					lStart--;
				}
				else lEnd++;
			}

			vector<int> result;
			for (int i = lStartIdx; i < lStartIdx + k; i++) {
				cout<<arr[i]<<", ";
				result.push_back(arr[i]);
			}
			cout<<endl;
			return result;
		}
};

int main() {
	vector<int> nums = {1, 2, 3, 4, 5, 6, 8, 9, 10};

	Solution test;
	test.findClosestElements(nums, 4, 4);
	test.findClosestElements(nums, 5, 4);
	test.findClosestElements(nums, 4, 0);
	test.findClosestElements(nums, 5, 0);
	test.findClosestElements(nums, 4, 11);
	test.findClosestElements(nums, 5, 11);
	test.findClosestElements(nums, 4, 10);
	test.findClosestElements(nums, 5, 10);
	test.findClosestElements(nums, 4, 7);
	test.findClosestElements(nums, 5, 7);
	test.findClosestElements(nums, 9, 7);
	test.findClosestElements(nums, 8, 7);
	test.findClosestElements(nums, 5, 2);
	test.findClosestElements(nums, 6, 2);

	return 0;
}
