#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 26 ms, faster than 7.36% of C++ online submissions for Minimum Falling Path Sum.
Memory Usage: 9.8 MB, less than 31.85% of C++ online submissions for Minimum Falling Path Sum.
*/

/*
nxn의 matrix가 주어지면, 이 matrix에서 아래로 떨어지는 숫자들의 합 중 가장 작은 합을 구하는 문제

dp 배열을 두고, 맨 아랫칸부터 위로 채우는 방식으로 풀어 보았음
맨 아랫칸은 matrix에 있는 그대로 채운 뒤, 한 행씩 올라가면서 인접해있는 칸 중 작은 값을 찾아서 그 칸의 숫자와 더함
그렇게 맨 위까지 올라오면, 맨 위의 숫자들만 비교해 주고 답을 리턴하면 됨
*/

class Solution {
public:
	int dp[100][100];

	int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();          // input의 가로 사이즈

		// 1. 맨 아래부터 위로 올라가면서 dp를 채울 것
		for (int i = 0; i < n; i++)
		{
			dp[n - 1][i] = matrix[n - 1][i];
		}

		for (int i = n - 2; i >= 0; i--)
		{
			int left_min = dp[i + 1][0];						// i-1, i 중 작은 값을 저장할 변수
			int right_min = min(dp[i + 1][0], dp[i + 1][1]);		// i, i+1 중 작은 값을 저장할 변수
			dp[i][0] = right_min + matrix[i][0];

			for (int j = 1; j < n - 1; j++)
			{
				// 이전의 right_min은 다음 값의 left_min이 됨
				left_min = right_min;
				right_min = min(dp[i + 1][j], dp[i + 1][j+1]);	// i, i+1 중 작은 값을 저장

				// left_min과 right_min 두 값을 비교해서 더 작은 값이 위로 올라가게 됨
				dp[i][j] = min(left_min, right_min) + matrix[i][j];
			}

			dp[i][n - 1] = right_min + matrix[i][n - 1];
		}

		// 2. 마지막 맨 윗줄에서 최소를 찾음
		int min_value = dp[0][0];
		for (int i = 1; i < n; i++)
		{
			if (min_value > dp[0][i]) {
				min_value = dp[0][i];
			}
		}

		return min_value;
	}
};

int main(void) {
	Solution sol = Solution();

	vector<vector<int> > arr({
		vector<int>({ 100,-42,-46,-41 }),
		vector<int>({ 31,97,10,-10 }),
		vector<int>({ -58,-51,82,89 }),
		vector<int>({ 51,81,69,-51 })
	});

	cout << sol.minFallingPathSum(arr);

	return 0;
}