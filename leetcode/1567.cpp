#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int dp[100000][2];

	int getMaxLen(vector<int>& nums) {
		int result;
		if (nums[0] > 0) {
			result = 1;
			dp[0][0] = 0;
			dp[0][1] = 1;
		}
		else {
			result = 0;
			if (nums[0] == 0) {
				dp[0][0] = 0;
			}
			else {
				dp[0][0] = 1;
			}
			dp[0][1] = 0;
		}

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == 0) {
				dp[i][0] = 0;
				dp[i][1] = 0;
			}
			else if (nums[i] > 0) {
				// 양수일 경우
				if (dp[i - 1][0] == 0) {
					dp[i][0] = 0;
				}
				else {
					dp[i][0] = dp[i - 1][0] + 1;
				}
				dp[i][1] = dp[i - 1][1] + 1;
			}
			else {
				// 음수일 경우
				if (dp[i - 1][0] == 0) {
					dp[i][1] = 0;
				}
				else {
					dp[i][1] = dp[i - 1][0] + 1;
				}
				dp[i][0] = dp[i - 1][1] + 1;
			}

			if (result < dp[i][1]) {
				result = dp[i][1];
			}
		}

		return result;
	}
};

int main(void) {
	Solution sol = Solution();

	vector<int> input = { -16,0,-5,2,2,-13,11,8 };
	sol.getMaxLen(input);

	return 0;
}