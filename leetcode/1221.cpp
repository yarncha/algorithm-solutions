/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split a String in Balanced Strings.
Memory Usage: 6.3 MB, less than 32.26% of C++ online submissions for Split a String in Balanced Strings.
*/

class Solution {
public:
	int balancedStringSplit(string s) {
		int result = 0;

		int num_of_R = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R') {
				num_of_R++;
			}
			else {
				num_of_R--;
			}

			if (num_of_R == 0) {
				result++;
			}
		}

		return result;
	}
};