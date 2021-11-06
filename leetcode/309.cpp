#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int result = 0;
		int current_min = prices[0];

		for (int i = 1; i < prices.size(); i++)
		{
			int calculated_value = prices[i] - current_min;
			if (calculated_value < 0) {
				// 이때가 살짝 다름
				// 여기서 이전것을 택할건지 다음것을 택할것인지 따져주기
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