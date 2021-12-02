#include <iostream>
using namespace std;

/*
Runtime: 36 ms, faster than 98.10% of C++ online submissions for Longest Palindromic Subsequence.
Memory Usage: 10.7 MB, less than 88.92% of C++ online submissions for Longest Palindromic Subsequence.
*/

class Solution {
public:
	int dp[1000][1000];       // i부터 j까지의 substring에서의 최대 palindromic subsequence의 길이를 저장할 배열

	int longestPalindromeSubseq(string s) {
		int size_of_input_string = s.size();        // 입력받은 string의 사이즈
		int answer = 0;								// 답으로 출력할 가장 긴 palindromic substring의 길이

		// 입력받은 string의 길이가 0일 때에는 0 return
		if (size_of_input_string == 0) {
			return 0;
		}

		// 한 글자일때는 그냥 palindromic substring이라고 볼 수 있음
		for (int i = 0; i < size_of_input_string; i++)
		{
			dp[i][i] = 1;
		}
		answer = 1;		// answer를 우선 한 글자로 세팅

		// x를 증가시키면서, 각 범위에 대해서 palindromic substring인지를 살핀다
		for (int x = 1; x < size_of_input_string; x++)
		{
			// 같은 글자가 2개 붙어있을 경우 true
			if (s[x] == s[x - 1]) {
				dp[x - 1][x] = 2;

				if (answer < 2) {
					answer = 2;
				}
			}
			else {
				dp[x - 1][x] = 1;
			}

			for (int y = x - 2; y >= 0; y--)
			{
				// s[x] s[y]가 같을 경우에는 중간 palindromic substring의 길이를 더해주면 됨
				if (s[x] == s[y]) {
					dp[y][x] = dp[y + 1][x - 1] + 2;
					if (answer < dp[y][x]) {
						answer = dp[y][x];
					}
				}
				else {
					dp[y][x] = max(dp[y][x-1],dp[y+1][x]);
				}
			}
		}

		return answer;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}