#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> result;

		// if rowIndex == 0
		result.push_back({ 1 });

		// if rowIndex == 1,2 ...
		if (rowIndex > 0) {
			result.push_back({ 1,1 });		// if rowIndex == 1

			for (int i = 2; i <= rowIndex; i++)
			{
				vector<int> temp;
				temp.clear();

				temp.push_back(1);
				for (int j = 1; j < i; j++)
				{
					temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
				}
				temp.push_back(1);

				result.push_back(temp);
			}
		}

		return result[rowIndex];
	}
};

int main(void) {
	Solution sol = Solution();

	sol.getRow(33);

	return 0;
}