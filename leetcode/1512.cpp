#include <iostream>
#include <vector>
using namespace std;

/*

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Good Pairs.
Memory Usage: 7.1 MB, less than 89.99% of C++ online submissions for Number of Good Pairs.

*/

class Solution {
public:
	int numIdenticalPairs(vector<int>& nums) {
		int num_of_numbers[101] = { 0, };

		// count all number's frequency
		for (int i = 0; i < nums.size(); i++)
		{
			num_of_numbers[nums[i]]++;
		}

		// count number of good pairs with the numbers that appeared more than once
		int num_of_good_pairs = 0;
		int current_number;
		for (int j = 1; j <= 100; j++)
		{
			if (num_of_numbers[j] > 1) {
				current_number = num_of_numbers[j] - 1;
				while (current_number > 0)
				{
					num_of_good_pairs += current_number;
					current_number--;
				}
			}
		}
		return num_of_good_pairs;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.numIdenticalPairs();
//
//	return 0;
//}