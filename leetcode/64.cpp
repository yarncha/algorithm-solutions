#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 8 ms, faster than 85.03% of C++ online submissions for Minimum Path Sum.
Memory Usage: 9.8 MB, less than 56.28% of C++ online submissions for Minimum Path Sum.
*/

class Solution {
public:
	int dp[200][200];       // (i,j)점까지 가는 최소 합

	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++)
		{
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		}
		for (int j = 1; j < n; j++)
		{
			dp[0][j] = grid[0][j] + dp[0][j - 1];
		}

		for (int x = 1; x < m; x++)
		{
			for (int y = 1; y < n; y++)
			{
				dp[x][y] = min(dp[x][y - 1], dp[x - 1][y]) + grid[x][y];
			}
		}

		return dp[m - 1][n - 1];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}