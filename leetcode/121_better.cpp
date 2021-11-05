#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 104 ms, faster than 94.56% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.4 MB, less than 53.38% of C++ online submissions for Best Time to Buy and Sell Stock.
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		int current_min = prices[0];

		for (int i = 1; i < prices.size(); i++)
		{
			int calculated_value = prices[i] - current_min;
			if (calculated_value < 0) {
				current_min = min(current_min, prices[i]);
			}
			else {
				result = max(result, calculated_value);
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