#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		int location = n;
		while (location < 2 * n)
		{
			nums.insert(nums.begin() + (2 * (location - n + 1) - 1), nums[location]);
			location++;
			nums.erase(nums.begin() + location);
		}
		return nums;
	}
};

int main(void) {
	Solution sol = Solution();
	vector<int> nums = { 1,2,3,4,4,3,2,1 };
	vector<int> a = sol.shuffle(nums, 4);
	return 0;
}