#include <iostream>
#include <vector>
using namespace std;

/*
가장 큰 정사각형을 찾는 문제. 직사각형이 아니고 정사각형이었는데 놓쳐서 문제 풀이에 시간이 걸렸다
정사각형이면 dp배열을 만든 뒤 그 위, 대각선 위, 왼쪽을 보고 제일 작은 숫자를 가져오면 된다. 만약 하나라도 0이 있으면 1 이상은 만들어지지 않으니까!

Runtime: 20 ms, faster than 94.96% of C++ online submissions for Maximal Square.
Memory Usage: 11.3 MB, less than 71.79% of C++ online submissions for Maximal Square.
*/

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		const int m = matrix.size();			// matrix의 가로 길이와 세로 길이
		const int n = matrix[0].size();
		int one_side_of_square = 0;				// 만들 수 있는 정사각형의 최대 길이
		int dp[300][300];						// (i,j)점을 오른쪽 아래 끝 꼭짓점으로 했을 때, 만들 수 있는 가장 큰 정사각형의 한 변을 저장할 배열

		for (int x = 0; x < m; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (x == 0 || y == 0 || matrix[x][y] == '0') {
					dp[x][y] = matrix[x][y] - '0';
				}
				else {
					dp[x][y] = 1 + min(dp[x - 1][y - 1], min(dp[x][y - 1], dp[x - 1][y]));
				}

				one_side_of_square = max(one_side_of_square, dp[x][y]);
			}
		}

		return one_side_of_square * one_side_of_square;
	}
};

int main(void) {
	Solution sol = Solution();

	vector<vector<char> > matrix({
	vector<char>({ '1','0','1','0','0' }),
	vector<char>({ '1','0','1','1','1' }),
	vector<char>({'1','1','1','1','1'}),
	vector<char>({'1','0','0','1','0'})
		});

	cout << sol.maximalSquare(matrix);

	return 0;
}