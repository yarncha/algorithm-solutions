#include <iostream>
#include <string>
using namespace std;

/*

Runtime: 4 ms, faster than 23.30% of C++ online submissions for Is Subsequence.
Memory Usage: 6.4 MB, less than 24.62% of C++ online submissions for Is Subsequence.

*/

class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.size() == 0) {
			// if string s is an empty string, it must be a subsequence of string t
			return true;
		}

		int current_s_char = 0;
		for (int i = 0; i < t.size(); i++) {
			if (s.at(current_s_char) == t.at(i)) {
				current_s_char++;
				if (current_s_char == s.size()) {
					return true;
				}
			}
		}

		if (current_s_char == s.size()) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main(void) {
	Solution sol = Solution();
	string s = "";
	string t = "ahbgdc";
	sol.isSubsequence(s, t);

	return 0;
}