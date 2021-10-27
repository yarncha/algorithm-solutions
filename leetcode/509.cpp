#include <iostream>
using namespace std;

class Solution {
public:
	int dp[31];
	int fib(int n) {
		if (n < 2) {
			dp[n] == n;
			return n;
		}
		if (dp[n] == 0) {
			dp[n] = fib(n - 1) + fib(n - 2);
		}
		return dp[n];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}