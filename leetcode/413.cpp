#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arithmetic Slices.
Memory Usage: 7.3 MB, less than 52.76% of C++ online submissions for Arithmetic Slices.
*/

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int input_size = nums.size();

		if (input_size < 3) {
			return 0;
		}

		int result = 0;
		int current_chain = 2;
		int dp[5000];
		dp[0] = dp[1] = nums[1] - nums[0];

		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = nums[i] - nums[i - 1];

			if (dp[i - 1] != dp[i]) {
				for (int j = current_chain - 2; j > 0; j--)
				{
					result += j;
				}

				current_chain = 2;
			}
			else {
				current_chain++;
			}
		}

		for (int j = current_chain - 2; j > 0; j--)
		{
			result += j;
		}

		return result;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}