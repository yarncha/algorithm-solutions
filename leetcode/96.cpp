#include <iostream>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
Memory Usage: 6 MB, less than 62.61% of C++ online submissions for Unique Binary Search Trees.
*/

class Solution {
public:
	int dp[20];         // i까지의 숫자가 있을 때, BST를 만들 수 있는 개수
	int numTrees(int n) {
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			int remain_number = i - 1;      // 맨 위의 루트 노드를 제외하고 남은 개수
			int left = 0;                   // 왼쪽으로 갈 요소의 개수
			int right = remain_number;      // 오른쪽으로 갈 요소의 개수
			int calculated_value = 0;		// dp[i]를 계산해본 값
			while (right >= 0)
			{
				calculated_value += dp[left] * dp[right];
				left++;
				right--;
			}
			dp[i] = calculated_value;
		}

		return dp[n];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}