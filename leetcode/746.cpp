#include <iostream>
#include <vector>
using namespace std;

/*

Runtime: 4 ms, faster than 90.31% of C++ online submissions for Min Cost Climbing Stairs.
Memory Usage: 13.6 MB, less than 66.50% of C++ online submissions for Min Cost Climbing Stairs.

*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int min_cost_to_reach_step[1001];   // min cost to reach ith step (ith step's cost included)
        
        min_cost_to_reach_step[0] = cost[0];
        min_cost_to_reach_step[1] = cost[1];

        for (int i = 2; i < cost.size(); i++)
        {
            min_cost_to_reach_step[i] = min(min_cost_to_reach_step[i-2], min_cost_to_reach_step[i-1])+ cost[i];
        }

        return min(min_cost_to_reach_step[cost.size()-2], min_cost_to_reach_step[cost.size()-1]);
    }
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}