#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 609 ms, faster than 20.20% of C++ online submissions for Range Sum Query 2D - Immutable.
Memory Usage: 147.9 MB, less than 93.30% of C++ online submissions for Range Sum Query 2D - Immutable.
*/

class NumMatrix {
public:
	int sum_of_section[200][200];			// (0,0) (i,j)을 각 꼭짓점으로 하는 직사각형 안의 원소의 합
	int size_of_row, size_of_column;		// 직사각형의 행/열 개수

	NumMatrix(vector<vector<int>>& matrix) {
		// matrix가 들어오면 sum_of_section을 채워줌
		size_of_row = matrix.size();
		size_of_column = matrix[0].size();

		sum_of_section[0][0] = matrix[0][0];

		for (int i = 1; i < size_of_column; i++)
		{
			sum_of_section[0][i] = sum_of_section[0][i - 1] + matrix[0][i];
		}
		for (int i = 1; i < size_of_row; i++)
		{
			sum_of_section[i][0] = sum_of_section[i - 1][0] + matrix[i][0];
		}

		for (int x = 1; x < size_of_row; x++)
		{
			for (int y = 1; y < size_of_column; y++)
			{
				sum_of_section[x][y] = matrix[x][y] + sum_of_section[x - 1][y] + sum_of_section[x][y - 1] - sum_of_section[x - 1][y - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int result = sum_of_section[row2][col2];

		if (row1 > 0) {
			result -= sum_of_section[row1 - 1][col2];
		}
		if (col1 > 0) {
			result -= sum_of_section[row2][col1 - 1];
		}
		if (row1 > 0 && col1 > 0) {
			result += sum_of_section[row1 - 1][col1 - 1];
		}

		return result;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

 //int main(void) {
 //	Solution sol = Solution();
 //
 //	cout << sol.qwer();
 //
 //	return 0;
 //}