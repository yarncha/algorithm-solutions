#include <iostream>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Replace All Digits with Characters.
Memory Usage: 6.3 MB, less than 5.53% of C++ online submissions for Replace All Digits with Characters.
*/

class Solution {
public:
	string replaceDigits(string s) {
		for (int i = 0; i < s.size() - 1; i += 2)
		{
			char input = s[i];
			int num = s[i + 1] - 48;

			s[i + 1] = input + num;
		}

		return s;
	}
};

int main(void) {
	Solution sol = Solution();

	sol.replaceDigits("a1c1e1");

	return 0;
}