#include <iostream>
#include <vector>
using namespace std;

/*

Runtime: 448 ms, faster than 12.18% of C++ online submissions for Jump Game.
Memory Usage: 48.1 MB, less than 99.93% of C++ online submissions for Jump Game.

*/

class Solution {
public:
	bool dp[10000];          // i번째 index에서 끝 index에 도달할 수 있는지를 저장한 배열

	bool canJump(vector<int>& nums) {
		int size_of_array = nums.size();        // nums의 원소 개수

		dp[size_of_array - 1] = true;
		for (int i = size_of_array - 2; i >= 0; i--)
		{
			for (int j = 1; j <= nums[i]; j++)
			{
				int next_index = i + j;
				if (next_index < size_of_array && dp[next_index] == true) {
					dp[i] = true;
					break;
				}
			}
		}

		return dp[0];
	}
};

int main(void) {
	Solution sol = Solution();

	vector<int> input = { 2,3,1,1,4 };
	sol.canJump(input);

	return 0;
}