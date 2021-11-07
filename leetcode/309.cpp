#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 11.2 MB, less than 47.56% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
*/

class Solution {
public:
	int max_profit[5000];       // i부터 마지막 날까지 얻을 수 있는 이득의 최대 양

	int maxProfit(vector<int>& prices) {
		int num_of_inputs = prices.size();			// prices의 원소의 개수
		int max_sell_value = prices[num_of_inputs - 1];	// 해당 범위까지의 배열에서 (i~마지막) 팔 때 얻을 수 있는 금액의 최대. 초기값은 마지막 원소로 된다.
		max_profit[num_of_inputs - 1] = 0;			// 마지막 날에 얻을 수 있는 이득의 양은 0이다

		for (int i = num_of_inputs - 2; i >= 0; i--)
		{
			// 뒤에서부터 이득의 최대 양을 구해본다.

			// 1. 먼저 해당 날짜부터 마지막 날짜 중 어떤 시점에 물건을 판다고 했을 때, 얻을 수 있는 가장 큰 금액을 구해본다.
			// 현재 새로 생긴 범위인 i에서 물건을 팔았을 때 얻을 수 있는 이득(prices[i]+max_profit[i+2])을 기존 값과 비교해서 구해본다. (j에 팔았을 때의 값은 prices[j]+max_profit[j+2]가 될 것이다. 1일의 쿨타임이 있으므로!)
			int new_sell_value = prices[i] + (i + 2 < num_of_inputs ? max_profit[i + 2] : 0);
			max_sell_value = max(max_sell_value, new_sell_value);

			// 2. 이제 해당 날짜에서 물건을 살 것인지(max_sell_value - prices[i], 즉 판매했을 때 이득에서 샀을 때의 가격을 빼 본 것), 또는 사지 않고 넘어갈 것인지(max_profit[i + 1])를 구해본다.
			max_profit[i] = max(max_profit[i + 1], max_sell_value - prices[i]);
		}

		return max_profit[0];		// 0번째까지 구했을 경우, 답은 max_profit[0]에 있어서 그냥 이를 리턴하면 됨
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}