#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 8 ms, faster than 56.68% of C++ online submissions for Triangle.
Memory Usage: 8.7 MB, less than 35.65% of C++ online submissions for Triangle.

주어진 삼각형 배열의 맨 꼭대기에서 아래까지 내려올 때, 지나가는 원소들의 최소합을 구하는 문제
*/

class Solution {
public:
	int dp[200][200];

	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();            // 주어진 삼각형 배열의 높이

		// 맨 아랫줄 채우기
		for (int i = 0; i < n; i++)
		{
			dp[n - 1][i] = triangle[n - 1][i];
		}

		// 아래에서 위로 채워나가기
		for (int x = n - 2; x >= 0; x--)
		{
			for (int y = 0; y <= x; y++)
			{
				dp[x][y] = min(dp[x + 1][y], dp[x + 1][y + 1]) + triangle[x][y];
			}
		}

		return dp[0][0];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}