#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dp[100][2];     // i번째 집을 방문하고 난 뒤의 max money를 저장할 배열, j가 0이면 첫 번째 집을 털지 않은 것, 1이면 털은 것

    int rob(vector<int>& nums) {
        int num_of_houses = nums.size();		// number of total houses

        if (num_of_houses == 1) {
            return nums[0];
        }

        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];

        for (int i = 2; i < num_of_houses; i++) {
            dp[i][0] = max(dp[i - 1][0], (dp[i - 2][0] + nums[i]));
            dp[i][1] = max(dp[i - 1][1], (dp[i - 2][1] + nums[i]));
        }

        int result = max(dp[num_of_houses - 1][0], dp[num_of_houses - 2][1]);

        return result;
    }
};

int main(void) {
	Solution sol = Solution();

    vector<int> a = {2,3,2};
	sol.rob(a);

	return 0;
}