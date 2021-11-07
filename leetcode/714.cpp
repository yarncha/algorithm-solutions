#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 92 ms, faster than 79.48% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
Memory Usage: 55.3 MB, less than 40.28% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
*/

class Solution {
public:
	int dp[50000];			// i~prices.size()-1의 부분수열에서 얻을 수 있는 최대 이득

	int maxProfit(vector<int>& prices, int fee) {
		int num_of_inputs = prices.size();							// 입력으로 주어진 prices의 크기
		dp[num_of_inputs - 1] = 0;									// 마지막에서 얻을 수 있는 이득은 0임
		int max_sell_value = prices[num_of_inputs - 1] - fee;		// 어떠한 시점에서 산 물건을 팔 았을 때 얻을 수 있는 최대 이득

		for (int i = num_of_inputs - 2; i >= 0; i--)
		{
			// 수열을 거꾸로 탐색하며 답을 찾는다.

			// 1. 해당 시점에서 물건을 사고, 최대 판매가에 물건을 팔았을 때 얻을 수 있는 이득을 구해 본다.
			int new_profit = prices[i] - fee + dp[i + 1];
			max_sell_value = max(max_sell_value, new_profit);

			// 2. 이 지점에서 물건을 살 것인지 사지 않을 것인지 결정한다.
			dp[i] = max(dp[i + 1], max_sell_value - prices[i]);
		}

		return dp[0];
	}
};

int main(void) {
	Solution sol = Solution();

	int input_fee = 2;
	vector<int> input_prices = { 1,3,2,8,4,9 };
	sol.maxProfit(input_prices, input_fee);

	return 0;
}