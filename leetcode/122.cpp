#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 4 ms, faster than 90.89% of C++ online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 13 MB, less than 86.56% of C++ online submissions for Best Time to Buy and Sell Stock II.
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		int current_stock_price = prices[0];

		for (int i = 1; i < prices.size(); i++)
		{
			int calculated_value = prices[i] - current_stock_price;
			if (calculated_value < 0) {
				current_stock_price = prices[i];
			}
			else {
				result += calculated_value;
				current_stock_price = prices[i];
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