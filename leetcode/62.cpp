#include <iostream>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
Memory Usage: 6 MB, less than 69.38% of C++ online submissions for Unique Paths.
*/

class Solution {
public:
    int num_of_possible_paths[100][100];
    int uniquePaths(int m, int n) {
        for (int i = 0; i < m; i++)
        {
            num_of_possible_paths[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            num_of_possible_paths[0][j] = 1;
        }
        for (int x = 1; x < m; x++)
        {
            for (int y = 1; y < n; y++)
            {
                num_of_possible_paths[x][y] = num_of_possible_paths[x-1][y]+num_of_possible_paths[x][y-1];
            }
        }
        return num_of_possible_paths[m-1][n-1];
    }
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}