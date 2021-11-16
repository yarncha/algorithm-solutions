#include <iostream>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
Memory Usage: 6.1 MB, less than 69.36% of C++ online submissions for Decode Ways.
*/

class Solution {
public:
	int numDecodings(string s) {
		int dp[100];
		int input_size = s.size();

		// 첫 번째 글자 처리
		if (s[0] == '0') {
			// Case 0 : 첫 번째 글자가 0일 경우 어떻게 해도 매칭되는 글자가 없게 됨
			return 0;
		}
		else {
			dp[0] = 1;
		}

		for (int i = 1; i < input_size; i++)
		{
			if (s[i] == '0') {
				// Case 1 : i(i>0)번째 글자가 0일 경우
				if (s[i - 1] == '1' || s[i - 1] == '2') {
					// Case 1-1 : 이전 글자가 1 또는 2여야지만 10, 20과 같이 글자를 붙여서 만들 수 있음
					//            따라서 dp[i] = dp[i-2]가 됨
					if (i == 1) {
						dp[i] = 1;
					}
					else {
						dp[i] = dp[i - 2];
					}
				}
				else {
					// Case 1-2 : 이전 글자가 0, 3~9 일때는 30, 90 이런 것들이 불가능하고 그렇다고 3/0으로 봐도 불가능하기 때문에 return 0;
					return 0;
				}
			}
			else {
				// Case 2 : i번째 글자가 0이 아닐 경우
				int calculated_value = s[i - 1] - 48;       // i-1, i 두 글자의 값을 계산해봄
				calculated_value *= 10;
				calculated_value += s[i] - 48;
				if (calculated_value >= 10 && calculated_value <= 26) {
					// Case 2-1 : 두 자리를 계산해본 값이 10~26으로 가능할 때
					if (i == 1) {
						dp[i] = 2;
					}
					else {
						dp[i] = dp[i - 1] + dp[i - 2];
					}
				}
				else {
					// Case 2-2 : 두 자리를 계산해본 값이 불가능할 때 (07, 27...)
					dp[i] = dp[i - 1];
				}
			}
		}

		return dp[s.size() - 1];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}