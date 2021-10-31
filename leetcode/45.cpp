#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 128 ms, faster than 40.16% of C++ online submissions for Jump Game II.
Memory Usage: 16.5 MB, less than 41.95% of C++ online submissions for Jump Game II.
*/

class Solution {
public:
	int dp[10000];

	int jump(vector<int>& nums) {
		int nums_size = nums.size();

		for (int i = 0; i < nums_size - 1; i++)
		{
			for (int j = 1; j <= nums[i]; j++)
			{
				int next_index = i + j;
				if (next_index < nums_size && dp[next_index] == 0) {
					dp[next_index] = dp[i] + 1;
				}
			}

			if (dp[nums_size - 1] != 0) {
				return dp[nums_size - 1];
			}
		}

		return dp[nums_size - 1];
	}
};

int main(void) {
	Solution sol = Solution();

	vector<int> input = { 2,3,1,1,4 };
	sol.jump(input);

	return 0;
}