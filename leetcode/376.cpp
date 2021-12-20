#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wiggle Subsequence.
Memory Usage: 7.1 MB, less than 72.74% of C++ online submissions for Wiggle Subsequence.
*/

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int dp[1000];		// i번째를 마지막으로 하는 subsequence중에서 가장 긴 길이의 wiggle subsequence
		int difference_of_element[1000];       // nums[i]-nums[i-1]의 값을 저장해둘 배열
		int size_of_input = nums.size();
		
		if (size_of_input==1) {
			return 1;
		}
		
		dp[0] = 1;

		if (nums[1] - nums[0] < 0) {
			difference_of_element[1] = -1;
			dp[1] = 2;
		}
		else if (nums[1] - nums[0] > 0) {
			difference_of_element[1] = 1;
			dp[1] = 2;
		}
		else {
			difference_of_element[1] = 0;
			dp[1] = 1;
		}

		for (int i = 2; i < size_of_input; i++)
		{
			if (nums[i] - nums[i - 1] < 0) {
				difference_of_element[i] = -1;
				if (difference_of_element[i-1] ==0 || difference_of_element[i-1]==1) {
					dp[i] = dp[i - 1] + 1;
				}
				else {
					dp[i] = dp[i - 1];
				}
			}
			else if (nums[i] - nums[i - 1] > 0) {
				difference_of_element[i] = 1;
				if (difference_of_element[i - 1] == 0 || difference_of_element[i - 1] == -1) {
					dp[i] = dp[i - 1] + 1;
				}
				else {
					dp[i] = dp[i - 1];
				}
			}
			else {
				difference_of_element[i] = difference_of_element[i-1];
				dp[i] = dp[i-1];
			}
		}

		return dp[size_of_input - 1];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}