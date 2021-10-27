#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {
		int start, end;
		int num_of_k = 0;
		int max_num_of_1 = 0;
		int cur_num_of_1 = 0;

		start = 0;
		end = 0;
		while (end < nums.size()) {
			if (nums[end] == 1) {
				end++;
				cur_num_of_1++;

				if (max_num_of_1 < cur_num_of_1) {
					max_num_of_1 = cur_num_of_1;
				}
			}
			else {
				if (num_of_k < k) {
					end++;
					num_of_k++;
					cur_num_of_1++;
					if (max_num_of_1 < cur_num_of_1) {
						max_num_of_1 = cur_num_of_1;
					}
				}
				else {
					while (nums[start] != 0)
					{
						cur_num_of_1--;
						start++;
					}

					// 0 빼주고 새로운 0 넣어줌
					start++;
					end++;
				}
			}
		}
		return max_num_of_1;
	}
};

int main(void) {
	Solution sol = Solution();

	vector<int> nums = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };

	sol.longestOnes(nums,2);

	return 0;
}