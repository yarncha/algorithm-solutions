#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;

		result.push_back({ 1 });

		if (numRows > 1) {
			result.push_back({ 1,1 });

			for (int i = 3; i <= numRows; i++)
			{
				vector<int> temp;
				temp.clear();

				temp.push_back(1);
				for (int j = 1; j < i - 1; j++)
				{
					temp.push_back(result[i - 2][j - 1] + result[i - 2][j]);
				}
				temp.push_back(1);

				result.push_back(temp);
			}
		}

		return result;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}