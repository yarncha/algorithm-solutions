#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
to make a triangle, all the one side of the triangle should be bigger than the sum of the other sides

Because of costing O(N^3) time, brute force approach is incorrect.
*/

/*
Runtime: 84 ms, faster than 84.64% of C++ online submissions for Valid Triangle Number.
Memory Usage: 12.8 MB, less than 20.85% of C++ online submissions for Valid Triangle Number.
*/

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int result = 0;  // num of valid combination

		// First, sort nums vector
		sort(nums.begin(), nums.end());

		// And pick biggest element i, and make the other side's range with it.
		for (int i = nums.size() - 1; i >= 0; i--) {
			int min_x = 0;
			int max_x = i - 1;

			while (min_x < max_x)
			{
				if (nums[i] < nums[min_x] + nums[max_x]) {
					result += max_x - min_x;
					max_x--;
				}
				else {
					min_x++;
				}
			}
		}

		return result;
	}
};

int main(void) {
	Solution sol = Solution();

	vector<int> a = { 4,2,3,4 };
	sol.triangleNumber(a);

	return 0;
}