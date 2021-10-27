#include <iostream>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for To Lower Case.
Memory Usage: 6.2 MB, less than 46.97% of C++ online submissions for To Lower Case.
*/

class Solution {
public:
	string toLowerCase(string s) {
		for (int i = 0; i < s.size(); i++)
		{
			//  aware of "s consists of printable ASCII characters."
			// s can have other characters that is not a alphabet
			if (s[i] <= 'Z' && s[i] >= 'A') {
				s[i] = s[i] + 32;
			}
		}

		return s;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}