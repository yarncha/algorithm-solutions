#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 6 ms, faster than 15.69% of C++ online submissions for Unique Paths II.
Memory Usage: 7.7 MB, less than 53.65% of C++ online submissions for Unique Paths II.
*/

class Solution {
public:
	int num_of_possible_paths[100][100];
	int size_of_rows, size_of_columns;

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		size_of_rows = obstacleGrid.size();
		size_of_columns = obstacleGrid[0].size();

		if (obstacleGrid[0][0] == 1) {
			num_of_possible_paths[0][0] = 0;
		}
		else {
			num_of_possible_paths[0][0] = 1;
		}

		for (int i = 1; i < size_of_rows; i++)
		{
			if (obstacleGrid[i][0] == 1) {
				num_of_possible_paths[i][0] = 0;
			}
			else {
				num_of_possible_paths[i][0] = num_of_possible_paths[i - 1][0];
			}
		}
		for (int j = 1; j < size_of_columns; j++)
		{
			if (obstacleGrid[0][j] == 1) {
				num_of_possible_paths[0][j] = 0;
			}
			else {
				num_of_possible_paths[0][j] = num_of_possible_paths[0][j - 1];
			}
		}

		for (int x = 1; x < size_of_rows; x++)
		{
			for (int y = 1; y < size_of_columns; y++)
			{
				if (obstacleGrid[x][y] == 1) {
					num_of_possible_paths[x][y] = 0;
				}
				else {
					num_of_possible_paths[x][y] = num_of_possible_paths[x - 1][y] + num_of_possible_paths[x][y - 1];
				}
			}
		}

		return num_of_possible_paths[size_of_rows - 1][size_of_columns - 1];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}