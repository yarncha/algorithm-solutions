#include <stdio.h>
#include <vector>
using namespace std;

// all integers except one form a pairwise
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			res ^= nums[i];
		}
		// due to the characteristics of the XOR operation, (a^b^b=a)
		// only one integer remains at the end of for loop

		return res;
	}
};

int main(void) {
	Solution sol = Solution();
	vector<int> nums = { 4,2,1,2,1 };

	int a = sol.singleNumber(nums);
	return 0;
}