#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
Runtime: 44 ms, faster than 5.42% of C++ online submissions for Remove Outermost Parentheses.
Memory Usage: 6.8 MB, less than 22.19% of C++ online submissions for Remove Outermost Parentheses.
*/

class Solution {
public:
	string removeOuterParentheses(string s) {
		stack<char> stack_for_s;
		string result = s;

		int start_index, end_index;

		for (int i = 0; i < result.size(); i++)
		{
			if (result.at(i) == '(') {
				if (stack_for_s.size() == 0) {
					start_index = i;
				}
				stack_for_s.push('(');
			}
			else {
				stack_for_s.pop();
				if (stack_for_s.size() == 0) {
					end_index = i;
					result.erase(start_index, 1);
					result.erase(end_index - 1, 1);
					i -= 2;
				}
			}
		}

		return result;
	}
};

int main(void) {
	Solution sol = Solution();

	sol.removeOuterParentheses("()()");

	return 0;
}