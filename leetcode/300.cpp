#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 204 ms, faster than 57.53% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 10.4 MB, less than 85.29% of C++ online submissions for Longest Increasing Subsequence.
*/

class Solution {
public:
	int dp[2500];           // i를 마지막으로하는 가장 긴 subsequence의 길이
	int lengthOfLIS(vector<int>& nums) {
		int answer = 1;
		dp[0] = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					if (answer < dp[i]) {
						answer = dp[i];
					}
				}
			}
		}

		return answer;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}