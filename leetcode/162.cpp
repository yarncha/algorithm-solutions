class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int result = nums.size() - 1;

		bool is_ascending = true;
		for (int i = 1; i < nums.size(); i++) {
			if (is_ascending) {
				if (nums[i - 1] > nums[i]) {
					result = i - 1;
					return result;
				}
			}
			else {
				if (nums[i - 1] > nums[i]) {
					is_ascending = false;
				}
				else {
					is_ascending = true;
				}
			}
		}

		return result;
	}
};