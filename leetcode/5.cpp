#include <iostream>
using namespace std;

/*
i부터 j까지가 palindromic substring인지를 dp배열에 저장하면서 계산해보면 됨

Runtime: 124 ms, faster than 52.10% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 25.5 MB, less than 42.59% of C++ online submissions for Longest Palindromic Substring.
*/

class Solution {
public:
	bool dp[1000][1000];       // i부터 j까지가 palindromic substring인지 여부를 저장할 배열

	string longestPalindrome(string s) {
		int size_of_input_string = s.size();        // 입력받은 string의 사이즈
		string answer = "";                         // 답으로 출력할 가장 긴 palindromic substring

		// 입력받은 string의 길이가 0일 때에는 "" return
		if (size_of_input_string == 0) {
			return answer;
		}

		// i부터 i까지, 즉 한 글자일때는 그냥 palindromic substring이라고 볼 수 있음
		for (int i = 0; i < size_of_input_string; i++)
		{
			dp[i][i] = true;
		}
		answer = s[0];		// answer를 우선 한 글자로 세팅

		// x를 증가시키면서, 각 범위에 대해서 palindromic substring인지를 살핀다
		for (int x = 1; x < size_of_input_string; x++)
		{
			// 같은 글자가 2개 붙어있을 경우 true
			if (s[x] == s[x - 1]) {
				dp[x - 1][x] = true;

				if (answer.size() < 2) {
					answer = s.substr(x-1, 2);
				}
			}
			else {
				dp[x - 1][x] = false;
			}

			// 또는 s[x] s[y]가 같은데, 그 사이 전부가 palindromic substring일 경우도 dp[y][x]가 palindromic substirng이라고 볼 수 있음
			for (int y = x - 2; y >= 0; y--)
			{
				if (s[x] == s[y] && dp[y + 1][x - 1]) {
					dp[y][x] = true;

					if (answer.size() < x - y + 1) {
						answer = s.substr(y, x - y + 1);
					}
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