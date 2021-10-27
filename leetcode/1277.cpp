#include <iostream>
#include <vector>
using namespace std;

/*

Runtime: 176 ms, faster than 14.98% of C++ online submissions for Count Square Submatrices with All Ones.
Memory Usage: 24 MB, less than 42.89% of C++ online submissions for Count Square Submatrices with All Ones.

*/

class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int number_of_squares = 0;		// total number of square submatrices with all 1s

		int is_square_with_all_one[300][300];
		int min_length = min(matrix.size(), matrix[0].size());

		// 1일 때 하나씩 세서 is_square_with_all_one 채우고 number_of_squares도 ++하기
		for (int x = 0; x < matrix.size(); x++)
		{
			for (int y = 0; y < matrix[0].size(); y++)
			{
				if (matrix[x][y] == 1) {
					is_square_with_all_one[x][y] = 1;
					number_of_squares++;
				}
				else {
					is_square_with_all_one[x][y] = 0;
				}
			}
		}

		for (int i = 2; i <= min_length; i++)
		{
			int max_row = matrix.size() - i;
			int max_column = matrix[0].size() - i;

			for (int j = 0; j <= max_row; j++)
			{
				for (int k = 0; k <= max_column; k++)
				{
					if (is_square_with_all_one[j][k] == 1 && is_square_with_all_one[j + 1][k] == 1 && is_square_with_all_one[j][k + 1] == 1 && is_square_with_all_one[j + 1][k + 1] == 1)
					{
						is_square_with_all_one[j][k] = 1;
						number_of_squares++;
					}
					else {
						is_square_with_all_one[j][k] = 0;
					}
				}
			}
		}

		return number_of_squares;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}