#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int min_cost_to_reach_step[1001];   // min cost to reach ith step (ith step's cost included)

	int SolveRecursively(int num_of_stairs, vector<int>& cost) {
		if (min_cost_to_reach_step[num_of_stairs] == 0 && num_of_stairs >= 2) {
			min_cost_to_reach_step[num_of_stairs] = min(SolveRecursively(num_of_stairs - 2, cost), SolveRecursively(num_of_stairs - 1, cost)) + cost[num_of_stairs];
		}

		return min_cost_to_reach_step[num_of_stairs];
	}

	int minCostClimbingStairs(vector<int>& cost) {
		int num_of_stairs = cost.size();

		min_cost_to_reach_step[0] = cost[0];
		min_cost_to_reach_step[1] = cost[1];

		SolveRecursively(num_of_stairs - 1, cost);

		return min(min_cost_to_reach_step[num_of_stairs - 2], min_cost_to_reach_step[num_of_stairs - 1]);
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}