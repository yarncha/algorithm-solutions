#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 1) {
			//if there is only one date in prices, return 0 cause there is no other date to choose
			return 0;
		}

		int	profit_of_buy_at[100001];			// if buy stock at ith day, profit_of_buy_at[i] will be the max profit
		int max_profit = 0;

		int maximum_sell_price = prices[prices.size() - 1];
		max_profit = maximum_sell_price - prices[prices.size() - 2];
		for (int current_buy_date = prices.size() - 3; current_buy_date >= 0; current_buy_date--)
		{
			if (maximum_sell_price < prices[current_buy_date + 1]) {
				maximum_sell_price = prices[current_buy_date + 1];
			}

			int temp = maximum_sell_price - prices[current_buy_date];
			if (temp > max_profit) {
				max_profit = temp;
			}
		}

		if (max_profit < 0) {
			max_profit = 0;
		}
		return max_profit;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}