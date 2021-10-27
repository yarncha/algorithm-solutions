#include <iostream>
#include <string>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
Memory Usage: 6.3 MB, less than 61.38% of C++ online submissions for Backspace String Compare.
*/

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		string new_s = "";
		string new_t = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s.at(i) == '#') {
				if (new_s != "") {
					new_s.pop_back();
				}
			}
			else {
				new_s.push_back(s.at(i));
			}
		}

		for (int j = 0; j < t.size(); j++)
		{
			if (t.at(j) == '#') {
				if(new_t != ""){
					new_t.pop_back();
				}
			}
			else {
				new_t.push_back(t.at(j));
			}
		}

		if (new_s == new_t) {
			return true;
		}
		return false;
	}
};

int main(void) {
	Solution sol = Solution();

	sol.backspaceCompare("y#fo##f","y#f#o##f");

	return 0;
}