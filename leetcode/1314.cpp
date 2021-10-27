#include <iostream>
#include <vector>
using namespace std;

/*

Runtime: 4 ms, faster than 99.15% of C++ online submissions for Matrix Block Sum.
Memory Usage: 9.4 MB, less than 76.49% of C++ online submissions for Matrix Block Sum.

*/

class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int sum_of_matrix_elements[100][100];     // sum of all elements in i*j square
		sum_of_matrix_elements[0][0] = mat[0][0];


		// 1. first, calculate all sum of all elements in i*j square
		int matrix_row_length = mat.size();
		int matrix_column_length = mat[0].size();

		for (int column = 1; column < matrix_column_length; column++) {
			sum_of_matrix_elements[0][column] = sum_of_matrix_elements[0][column - 1] + mat[0][column];
		}

		for (int row = 1; row < matrix_row_length; row++) {
			sum_of_matrix_elements[row][0] = sum_of_matrix_elements[row - 1][0] + mat[row][0];
		}

		for (int i = 1; i < matrix_row_length; i++) {
			for (int j = 1; j < matrix_column_length; j++) {
				sum_of_matrix_elements[i][j] = mat[i][j] + sum_of_matrix_elements[i][j - 1] + sum_of_matrix_elements[i - 1][j] - sum_of_matrix_elements[i - 1][j - 1];
			}
		}


		// 2. and calculate answer square with the upper array
		vector<vector<int>> answer(matrix_row_length, vector<int>(matrix_column_length));       // the answer array
		for (int i = 0; i < matrix_row_length; i++) {
			for (int j = 0; j < matrix_column_length; j++) {
				int down_x = min(i + k, matrix_row_length - 1);
				int down_y = min(j + k, matrix_column_length - 1);
				int up_x = i - k - 1;
				int up_y = j - k - 1;
				answer[i][j] = sum_of_matrix_elements[down_x][down_y];
				if (up_x >= 0 && up_y >= 0) {
					answer[i][j] = answer[i][j] - sum_of_matrix_elements[down_x][up_y] - sum_of_matrix_elements[up_x][down_y] + sum_of_matrix_elements[up_x][up_y];
				}
				else if (up_x >= 0) {
					answer[i][j] = answer[i][j] - sum_of_matrix_elements[up_x][down_y];
				}
				else if (up_y >= 0) {
					answer[i][j] = answer[i][j] - sum_of_matrix_elements[down_x][up_y];
				}
			}
		}
		return answer;
	}
};

int main(void) {
	Solution sol = Solution();

	vector<vector<int>> q(3, vector<int>(3));
	q[0] = { 1, 2, 3 };	q[1] = { 4, 5, 6 };	q[2] = { 7, 8, 9 };
	sol.matrixBlockSum(q, 1);

	return 0;
}