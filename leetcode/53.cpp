#include <iostream>
#include <vector>
using namespace std;

/*

Runtime: 104 ms
Memory Usage: 68.2 MB

*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max_sum_of_subarray[100001];     // the max sum of subarray including last element i
		int maximum = nums[0];
		max_sum_of_subarray[0] = maximum;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > nums[i] + max_sum_of_subarray[i - 1]) {
				max_sum_of_subarray[i] = nums[i];
			}
			else {
				max_sum_of_subarray[i] = nums[i] + max_sum_of_subarray[i - 1];
			}

			if (maximum < max_sum_of_subarray[i]) {
				maximum = max_sum_of_subarray[i];
			}
		}

		return maximum;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}