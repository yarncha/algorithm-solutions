#include <iostream>
using namespace std;

/*

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
Memory Usage: 5.9 MB, less than 49.39% of C++ online submissions for Climbing Stairs.

*/

class Solution {
public:
	int climbStairs(int n) {
		int number_of_cases_to_reach_the_top[46];       // when it takes i steps to reach the top,
														// this array has the number of cases to reach the top of the stair
		number_of_cases_to_reach_the_top[1] = 1;
		number_of_cases_to_reach_the_top[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			// when the distance to reach the top is i, there is two ways to reach that
			// one is to add "1" to the case of number_of_cases_to_reach_the_top[i-1]
			// and the last is to add "2" to the case of number_of_cases_to_reach_the_top[i-2]
			number_of_cases_to_reach_the_top[i] = number_of_cases_to_reach_the_top[i - 1] + number_of_cases_to_reach_the_top[i - 2];
		}

		return number_of_cases_to_reach_the_top[n];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}