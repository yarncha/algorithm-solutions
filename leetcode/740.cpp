#include <iostream>
#include <vector>
using namespace std;

/*

Runtime: 4 ms, faster than 93.61% of C++ online submissions for Delete and Earn.
Memory Usage: 9.2 MB, less than 78.37% of C++ online submissions for Delete and Earn.

*/

class Solution {
public:
	int frequency_of_numbers[10001];
	int dp[10001];
	int min_num = 10001;
	int max_num = 0;

	int deleteAndEarn(vector<int>& nums) {
		// nums의 숫자의 개수를 세고, 가장 큰 숫자와 가장 작은 숫자를 찾는다.
		for (int i = 0; i < nums.size(); i++)
		{
			frequency_of_numbers[nums[i]]++;
			if (min_num > nums[i]) {
				min_num = nums[i];
			}
			if (max_num < nums[i]) {
				max_num = nums[i];
			}
		}

		// 빈도 분석한 결과를 토대로, 가장 큰 점수를 계산해본다
		dp[min_num] = min_num * frequency_of_numbers[min_num];
		if (nums.size() >= 2) {
			dp[min_num + 1] = (min_num + 1) * frequency_of_numbers[min_num + 1];
			for (int j = min_num + 1; j <= max_num; j++)
			{
				dp[j] = max(dp[j - 1], dp[j - 2] + (j * frequency_of_numbers[j]));
			}
		}

		return dp[max_num];
	}
};

int main(void) {
	Solution sol = Solution();

	vector<int> a = { 3,1 };
	sol.deleteAndEarn(a);

	return 0;
}