#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

/*

Runtime: 4 ms, faster than 89.54% of C++ online submissions for Move Zeroes.
Memory Usage: 9 MB, less than 10.12% of C++ online submissions for Move Zeroes.

*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int finished_point = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0) {
				nums[finished_point] = nums[i];
				finished_point++;
			}
		}
		// fill zero to the vector
		while (finished_point < nums.size())
		{
			nums[finished_point] = 0;
			finished_point++;
		}
	}
};

int main(void) {
	Solution sol = Solution();
	vector<int> a = { 1,2,0,3,0,0,4,5 };
	sol.moveZeroes(a);
	return 0;
}