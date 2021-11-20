#include <iostream>
using namespace std;

class Solution {
public:
	int dp[1691];

	int nthUglyNumber(int n) {
		dp[0] = 1;

		int counter_2 = 0;
		int counter_3 = 0;
		int counter_5 = 0;

		for (int i = 1; i < n; i++)
		{
			int next_value = min(2 * dp[counter_2], min(3 * dp[counter_3], 5 * dp[counter_5]));

			dp[i] = next_value;

			if (next_value == 2 * dp[counter_2]) {
				counter_2++;
			}
			if (next_value == 3 * dp[counter_3]) {
				counter_3++;
			}
			if (next_value == 5 * dp[counter_5]) {
				counter_5++;
			}
		}
		return dp[n - 1];
	}
};

int main(void) {
	Solution sol = Solution();

	cout << sol.nthUglyNumber(10);

	return 0;
}