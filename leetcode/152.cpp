#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 8 ms, faster than 40.15% of C++ online submissions for Maximum Product Subarray.
Memory Usage: 12 MB, less than 7.90% of C++ online submissions for Maximum Product Subarray.
*/

class Solution {
public:
	int dp[20000][2];		// i번째 원소에서 부분곱을 구해볼 때, j==0에 들어가는 값은 곱이 최소가 되는 값 j=1에 들어가는 값은 곱이 최대가 되는 값

	int maxProduct(vector<int>& nums) {
		int result = nums[0];
		dp[0][0] = nums[0];
		dp[0][1] = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == 0) {
				// 0일 때에는 해당 값을 포함하는 부분곱의 최대/최소 값이 모두 0이 된다.
				dp[i][0] = dp[i][1] = 0;
			}
			else if (nums[i] > 0) {
				// 현재 원소가 양수인지 음수인지에 따라서 부분곱의 최대, 최소값을 구하도록 한다
				dp[i][0] = min(nums[i], dp[i - 1][0] * nums[i]);
				dp[i][1] = max(nums[i], dp[i - 1][1] * nums[i]);
			}
			else {
				dp[i][0] = min(nums[i], dp[i - 1][1] * nums[i]);
				dp[i][1] = max(nums[i], dp[i - 1][0] * nums[i]);
			}

			result = max(result, dp[i][1]);
		}

		return result;
	}
};

int main(void) {
	Solution sol = Solution();

	vector<int> input = { 2,3,-2,4 };
	sol.maxProduct(input);

	return 0;
}